
--- GG/adobe/cmath.hpp.orig	2011-01-05 13:35:35.631436941 +0200
+++ GG/adobe/cmath.hpp	2011-01-05 13:35:50.973926288 +0200
@@ -37,14 +37,14 @@
 
 #define ADOBE_HAS_CPP_CMATH 
 
-#elif ((__GNUC__ == 4) && (__GNUC_MINOR__ <= 4))
+#elif ((__GNUC__ == 4) && (__GNUC_MINOR__ <= 6))
 /*
     The currently supported version of GNUC has C99 extensions in math.h. But no TR1 extensions.
 */
 #define ADOBE_HAS_C99_MATH_H
  
 #else
-#error "Unknown GCC compiler configuration for cmath (last known version is 4.0.1)."
+#error "Unknown GCC compiler configuration for cmath (last known version is 4.6.0)."
 #endif
 
 #elif defined(_MSC_VER)


