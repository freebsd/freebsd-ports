--- deps/uv/src/uv-unix.c.orig	2011-08-02 15:17:41.000000000 +0800
+++ deps/uv/src/uv-unix.c	2011-08-03 16:27:45.000000000 +0800
@@ -54,6 +54,7 @@
 
 #if defined(__FreeBSD__)
 #include <sys/sysctl.h>
+#include <sys/wait.h>
 #endif
 
 
