-- libc++ before 20 (FreeBSD 15.x) lacks floating-point std::from_chars

--- opennn/core/string_utilities.h.orig
+++ opennn/core/string_utilities.h
@@ -11,7 +11,8 @@
 #include <initializer_list>
 #include <limits>
 #include <type_traits>
-#ifdef __APPLE__
+#if defined(__APPLE__) || (defined(__FreeBSD__) && defined(_LIBCPP_VERSION) && _LIBCPP_VERSION < 200000)
+#define OPENNN_NO_FP_FROM_CHARS
 #include <cstdlib>
 #include <cerrno>
 #include <cmath>
@@ -21,7 +22,7 @@
 namespace opennn
 {
 
-#ifdef __APPLE__
+#ifdef OPENNN_NO_FP_FROM_CHARS
 
     template <typename T>
     inline from_chars_result from_chars(const char* first, const char* last, T& value)
