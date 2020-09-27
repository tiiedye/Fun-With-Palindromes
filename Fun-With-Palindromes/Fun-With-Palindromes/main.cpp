#include <cctype>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

bool is_palindrome(const std::string& s) {
    // You must implement this function.
    // Since we are learning the STL - use a deque to solve the problem.
    std::deque<char> deque_char;

    for (char c : s) {
        if (std::isalpha(c)) {
            deque_char.push_back(std::toupper(c));
        }
    }

    char char1{};
    char char2{};

    // loop to compare front and back characters of the string.
    while (deque_char.size() > 1) {
        char1 = deque_char.front();
        char2 = deque_char.back();
        deque_char.pop_front();
        deque_char.pop_back();

        if (char1 != char2) {
            return false;
            // returns false and ends loop if characters do not match at any point through the loop.
        }
    }

    // returns true if the loop goes all the way through the string and does not return false at any point.
    return true;
}

int main() {
    std::vector<std::string> test_strings{ "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome" };

    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
    for (const auto& s : test_strings) {
        std::cout << std::setw(8) << std::left << is_palindrome(s) << s << std::endl;
    }
    std::cout << std::endl;
    return 0;
}