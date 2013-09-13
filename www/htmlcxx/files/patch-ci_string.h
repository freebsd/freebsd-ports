--- html/ci_string.h.orig	2013-09-13 10:48:21.000000000 +0800
+++ html/ci_string.h	2013-09-13 10:48:35.000000000 +0800
@@ -4,16 +4,7 @@
 #include <cctype>
 #include <string>
 
-#if __GNUC__ >= 3
-#include <bits/char_traits.h>
 struct ci_char_traits : public std::char_traits<char>
-#elif defined(__GNUC__)
-#include <std/straits.h>
-struct ci_char_traits : public std::string_char_traits<char>
-#else 
-//Hope string already include it
-struct ci_char_traits : public std::char_traits<char>
-#endif
 
 // just inherit all the other functions
 //  that we don't need to override
