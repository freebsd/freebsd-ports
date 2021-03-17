--- random/jitterentropy-base.c.orig	2021-03-16 20:10:57.561791000 -0700
+++ random/jitterentropy-base.c	2021-02-12 03:23:24.000000000 -0800
@@ -51,6 +51,7 @@
 
 #undef _FORTIFY_SOURCE
 #pragma GCC optimize ("O0")
+#pragma clang optimize off
 
 #include "jitterentropy.h"
 
