--- src/smack1.c.orig	2017-06-06 03:59:39 UTC
+++ src/smack1.c
@@ -115,6 +115,8 @@
 #include "pixie-timer.h"
 #if defined(_MSC_VER)
 #include <intrin.h>
+#elif defined(__llvm__) && (defined(__amd64__) || defined(__i386__))
+#include <x86intrin.h>
 #elif defined(__GNUC__)
 static __inline__ unsigned long long __rdtsc(void)
 {
