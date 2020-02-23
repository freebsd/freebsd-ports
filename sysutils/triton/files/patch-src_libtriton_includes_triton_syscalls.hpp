--- src/libtriton/includes/triton/syscalls.hpp.orig	2020-02-22 23:40:16 UTC
+++ src/libtriton/includes/triton/syscalls.hpp
@@ -10,7 +10,7 @@
 
 #if defined(__unix__) || defined(__APPLE__)
 
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
   #include <sys/syscall.h>
 #elif defined(__ANDROID___)
   #if defined(__aarch64__)
