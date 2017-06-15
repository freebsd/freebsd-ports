--- fsmonitor/linux/inotify_stubs.c.orig	2017-03-23 16:25:03 UTC
+++ fsmonitor/linux/inotify_stubs.c
@@ -27,9 +27,13 @@
 #include <caml/signals.h>
 #include <caml/callback.h>
 
+#include <sys/param.h>
+
+#if !defined(__FreeBSD__)
 #include <features.h>
+#endif
 
-#if __GLIBC__ >= 2 && __GLIBC_MINOR__ >= 4
+#if (__GLIBC__ >= 2 && __GLIBC_MINOR__ >= 4) || defined(__FreeBSD__)
 #define GLIBC_SUPPORT_INOTIFY 1
 #else
 #define GLIBC_SUPPORT_INOTIFY 0
