--- src/c/lm/rng/XORShift.cpp.orig	2018-09-09 20:03:05 UTC
+++ src/c/lm/rng/XORShift.cpp
@@ -42,6 +42,11 @@
 #include "lm/rng/RandomGenerator.h"
 #include "lm/rng/XORShift.h"
 
+// sincos doesn't exist on all current (2018-08) FreeBSD versions
+#if defined(__FreeBSD__)
+#  define sincos(x,s,c) *s = sin(x); *c = cos(x);
+#endif
+
 namespace lm {
 namespace rng {
 
