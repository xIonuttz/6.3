#include <iostream>
#include <cmath>

class Complex {
private:
    double real;
    double imaginary;

public:
    Complex(double r, double i) : real(r), imaginary(i) {}

    // Overload + operator for sum
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    // Overload ~ operator for absolute value (module)
    double operator~() const {
        return std::sqrt(real * real + imaginary * imaginary);
    }

    // Function for power (assuming exponent is 2 by default)
    Complex power(int exponent = 2) const {
        if (exponent == 2) {
            // Square the complex number
            return Complex(real * real - imaginary * imaginary, 2 * real * imaginary);
        }
        else {
            // You can implement additional logic for higher exponents if needed
            std::cerr << "Exponentiation higher than 2 is not supported in this example.\n";
            return Complex(0, 0);
        }
    }

    // Overload < operator to compare by module
    bool operator<(const Complex& other) const {
        return (~(*this)) < (~other);
    }

    // Display the complex number
    void display() const {
        std::cout << "(" << real << " + " << imaginary << "i)" << std::endl;
    }
};

int main() {
    Complex complexNumber1(3, 4);
    Complex complexNumber2(1, -2);

    // Compare two complex numbers by module using operator <
    if (complexNumber1 < complexNumber2) {
        std::cout << "complexNumber1 has a smaller module than complexNumber2.\n";
    }
    else {
        std::cout << "complexNumber1 has a larger or equal module compared to complexNumber2.\n";
    }

    return 0;
}
