--- fastops/core/SIMDFunctions.h.orig	2020-05-06 07:23:43 UTC
+++ fastops/core/SIMDFunctions.h
@@ -9,6 +9,7 @@
 #include <emmintrin.h>
 #include <xmmintrin.h>
 #include <immintrin.h>
+#include <stdint.h>
 
 #if defined(__clang_major__) && !defined(__apple_build_version__) && __clang_major__ >= 8
 #   define Y_HAVE_NEW_INTRINSICS
