--- lavtools/liblavplay.c.orig
+++ lavtools/liblavplay.c
@@ -43,7 +43,12 @@
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
