--- Clp/src/ClpPackedMatrix.cpp.orig	2019-12-29 17:14:00 UTC
+++ Clp/src/ClpPackedMatrix.cpp
@@ -6752,7 +6752,7 @@ ClpPackedMatrix3::ClpPackedMatrix3()
 #elif defined(__arm__)
 #include <arm_neon.h>
 #else
-#include <immintrin.h>
+//#include <immintrin.h>
 //#include <fmaintrin.h>
 #endif
 /* Constructor from copy. */
