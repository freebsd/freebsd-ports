--- random/jitterentropy-base.c.orig	2021-08-22 05:57:34.000000000 -0700
+++ random/jitterentropy-base.c	2021-08-23 14:05:29.630091000 -0700
@@ -52,6 +52,7 @@
 #undef _FORTIFY_SOURCE
 #ifdef __OPTIMIZE__
 #pragma GCC optimize ("O0")
+#pragma clang optimize off
 #endif
 
 #include "jitterentropy.h"
