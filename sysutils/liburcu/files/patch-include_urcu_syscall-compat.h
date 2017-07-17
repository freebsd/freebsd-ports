--- include/urcu/syscall-compat.h.orig	2017-06-12 23:02:38 UTC
+++ include/urcu/syscall-compat.h
@@ -32,7 +32,7 @@
 #elif defined(__linux__) || defined(__GLIBC__)
 #include <syscall.h>
 
-#elif defined(__CYGWIN__) || defined(__APPLE__)
+#elif defined(__CYGWIN__) || defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__)
 /* Don't include anything on Cygwin or MacOSX. */
 
 #else
