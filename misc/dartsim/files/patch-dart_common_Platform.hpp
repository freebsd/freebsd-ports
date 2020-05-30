--- dart/common/Platform.hpp.orig	2019-08-17 03:14:11 UTC
+++ dart/common/Platform.hpp
@@ -43,6 +43,15 @@
 #define DART_ARCH_32BITS   1
 #endif
 
+#elif defined(__FreeBSD__)
+
+#define DART_OS_FREEBSD      1
+#if __x86_64__ || __ppc64__
+#define DART_ARCH_64BITS   1
+#else
+#define DART_ARCH_32BITS   1
+#endif
+
 #elif defined(__APPLE__)
 
 #define DART_OS_MACOS      1
@@ -75,6 +84,10 @@
 
 #ifndef DART_OS_LINUX
   #define DART_OS_LINUX    0
+#endif
+
+#ifndef DART_OS_FREEBSD
+  #define DART_OS_FREEBSD    0
 #endif
 
 #ifndef DART_OS_MACOS
