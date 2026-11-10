-- libc++ before 20 (FreeBSD 15.x) lacks floating-point std::from_chars

--- opennn/core/json.cpp.orig
+++ opennn/core/json.cpp
@@ -13,7 +13,7 @@
 #include <cstring>
 #include <fstream>
 #include <limits>
-#if defined(__APPLE__) && defined(_LIBCPP_VERSION)
+#if (defined(__APPLE__) || (defined(__FreeBSD__) && _LIBCPP_VERSION < 200000)) && defined(_LIBCPP_VERSION)
 #include <locale>
 #include <sstream>
 #endif
@@ -26,7 +26,7 @@
 
 bool parse_double_exact(std::string_view text, double& value)
 {
-#if defined(__APPLE__) && defined(_LIBCPP_VERSION)
+#if (defined(__APPLE__) || (defined(__FreeBSD__) && _LIBCPP_VERSION < 200000)) && defined(_LIBCPP_VERSION)
     // Xcode 16's libc++ declares floating-point from_chars but does not
     // implement it. The classic locale preserves JSON's decimal grammar.
     std::istringstream stream{std::string(text)};
