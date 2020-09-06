--- ortools/base/integral_types.h.orig	2020-09-06 04:04:04 UTC
+++ ortools/base/integral_types.h
@@ -24,7 +24,7 @@
 #define ARCH_K8
 #elif defined(__APPLE__) && defined(__GNUC__)
 #define ARCH_K8  // We only support 64 bit on Mac OS X.
-#elif defined(__GNUC__) && defined(__LP64__) && !defined(__aarch64__)
+#elif defined(__GNUC__) && defined(__LP64__) && !defined(__aarch64__) && !defined(__powerpc64__)
 #define ARCH_K8  // Linux x86_64
 #endif
 
