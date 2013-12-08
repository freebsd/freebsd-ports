--- GG/adobe/cmath.hpp.orig	2011-08-29 15:14:45.000000000 +0200
+++ GG/adobe/cmath.hpp	2013-12-08 12:40:51.000000000 +0100
@@ -31,21 +31,7 @@
 #define ADOBE_HAS_C99_STD_MATH_H
 
 #elif defined(__GNUC__)
-
-// Guessing at gcc 3 support
-#if  (__GNUC__ == 3) && (__GNUC_MINOR__ > 2)
-
-#define ADOBE_HAS_CPP_CMATH 
-
-#elif ((__GNUC__ == 4) && (__GNUC_MINOR__ <= 6))
-/*
-    The currently supported version of GNUC has C99 extensions in math.h. But no TR1 extensions.
-*/
 #define ADOBE_HAS_C99_MATH_H
- 
-#else
-#error "Unknown GCC compiler configuration for cmath (last known version is 4.0.1)."
-#endif
 
 #elif defined(_MSC_VER)
 
