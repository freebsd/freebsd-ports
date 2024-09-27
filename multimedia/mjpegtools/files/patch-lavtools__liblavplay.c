--- lavtools/liblavplay.c.orig	2021-09-05 06:14:13 UTC
+++ lavtools/liblavplay.c
@@ -44,7 +44,12 @@
 #include <sys/resource.h>
 #include <sys/wait.h>
 #ifdef HAVE_V4L
+#ifdef __linux
 #include <sys/vfs.h>
+#else
+#include <sys/param.h>
+#include <sys/mount.h>
+#endif
 #endif
 
 #ifndef X_DISPLAY_MISSING
