--- src/Common/CxParse1.cpp.orig	2026-11-02 03:17:42 UTC
+++ src/Common/CxParse1.cpp
@@ -1410,12 +1410,13 @@ namespace ct {
 
 // trim from left
 void TrimLeft(std::string &s) {
-   s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
+   // std::not1/std::ptr_fun are gone from <functional> in C++17 and later, and libc++ enforces that.
+   s.erase(s.begin(), std::find_if_not(s.begin(), s.end(), [](unsigned char c) { return std::isspace(c); }));
 }
 
 // trim from right
 void TrimRight(std::string &s) {
-   s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
+   s.erase(std::find_if_not(s.rbegin(), s.rend(), [](unsigned char c) { return std::isspace(c); }).base(), s.end());
 }
 
 // trim from both ends
