#include <SFML/Graphics.hpp>
#include <iostream>

void createCircle(sf::CircleShape& circle, sf::Vector2f position, sf::Color color, float radius)
{
    circle.setRadius(radius);
    circle.setFillColor(color);
    circle.setPosition(position);
}

void createRectangle(sf::RectangleShape& rectangle, sf::Vector2f position, sf::Color color, sf::Vector2f size)
{
    rectangle.setSize(size);
    rectangle.setFillColor(color);
    rectangle.setPosition(position);
}

void bounceRectangle(sf::RectangleShape& rectangle, int wWidth, int wHeight, sf::Vector2f& rectangleVelocity)
{
    // Update rectangle position
    sf::Vector2f rectanglePosition = rectangle.getPosition();
    rectanglePosition += rectangleVelocity;
    rectangle.setPosition(rectanglePosition);

    // Bounce off the edges
    if (rectanglePosition.x < 0 || rectanglePosition.x + rectangle.getSize().x > wWidth)
    {
        rectangleVelocity.x *= -1.0f;
    }

    if (rectanglePosition.y < 0 || rectanglePosition.y + rectangle.getSize().y > wHeight)
    {
        rectangleVelocity.y *= -1.0f;
    }
}

void bounceCircle(sf::CircleShape& circle, int wWidth, int wHeight, sf::Vector2f& circleVelocity)
{
    // Ýkinci daireyi güncelliyoruz
    sf::Vector2f circlePosition = circle.getPosition();
    circlePosition += circleVelocity;
    circle.setPosition(circlePosition);

    if (circlePosition.x < 0 || circlePosition.x + circle.getRadius() * 2 > wWidth)
    {
        circleVelocity.x *= -1.0f;
    }

    if (circlePosition.y < 0 || circlePosition.y + circle.getRadius() * 2 > wHeight)
    {
        circleVelocity.y *= -1.0f;
    }
}

int main()
{
    // screen settings
    const int wWidth = 800;
    const int wHeight = 600;
    sf::RenderWindow window(sf::VideoMode(wWidth, wHeight), "Simulation");
    window.setFramerateLimit(60);

    // Circles

    sf::CircleShape rCircle;
    createCircle(rCircle, sf::Vector2f(500.0f, 300.0f), sf::Color(255, 10, 0), 90.0f);
    sf::Vector2f rCircleVelocity(10.0f, 10.0f);

    sf::CircleShape bCircle;
    createCircle(bCircle, sf::Vector2f(200.0f, 200.0f), sf::Color::Blue, 50.0f);
    sf::Vector2f bCircleVelocity(2.0f, 5.0f);

    sf::CircleShape pCircle;
    createCircle(pCircle, sf::Vector2f(300.0f, 300.0f), sf::Color(255, 0, 255), 75);
    sf::Vector2f pCircleVelocity(5.0f, 8.0f);


    // Rectangles

    sf::RectangleShape mRectangle;
    createRectangle(mRectangle, sf::Vector2f(400.0f, 300.0f), sf::Color(155, 25, 148), sf::Vector2f(250.0f, 80.0f));
    sf::Vector2f rectangleVelocity(8.0f, 5.0f);

    sf::RectangleShape tRectangle;
    createRectangle(tRectangle, sf::Vector2f(255.0f, 255.0f), sf::Color(158, 221, 255), sf::Vector2f(80.0f, 270.0f));
    sf::Vector2f tRectangleVelocity(25.0f, 10.0f);

    while (window.isOpen())
    {
        // event handling
        sf::Event event;
        while (window.pollEvent(event))
        {
            // this event triggers when the window is closed
            if (event.type == sf::Event::Closed)
                window.close();
        }

        bounceCircle(rCircle, wWidth, wHeight, rCircleVelocity);
        bounceCircle(bCircle, wWidth, wHeight, bCircleVelocity);
        bounceCircle(pCircle, wWidth, wHeight, pCircleVelocity);

        bounceRectangle(mRectangle, wWidth, wHeight, rectangleVelocity);
        bounceRectangle(tRectangle, wWidth, wHeight, tRectangleVelocity);

        window.clear();
        window.draw(mRectangle);
        window.draw(tRectangle);
        window.draw(rCircle);
        window.draw(bCircle);
        window.draw(pCircle);
        window.display();
    }

    return 0;
}
