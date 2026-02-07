--- src/intrinsics.h.orig	2024-10-15 15:55:56 UTC
+++ src/intrinsics.h
@@ -20,7 +20,9 @@
  */
 
 
-#if defined(__ICC)
+#if defined(__arm__) || defined(__aarch64__)
+#include <sse2neon.h>
+#elif defined(__ICC)
 #include <xmmintrin.h>
 #elif defined(__GNUC__)
 #include <x86intrin.h>
