--- thunar-vfs/thunar-vfs-thumb.c.orig	Thu Sep  7 15:22:21 2006
+++ thunar-vfs/thunar-vfs-thumb.c	Thu Sep  7 15:22:32 2006
@@ -28,14 +28,14 @@
 #ifdef HAVE_SYS_MMAN_H
 #include <sys/mman.h>
 #endif
+#ifdef HAVE_SYS_TIME_H
+#include <sys/time.h>
+#endif
 #ifdef HAVE_SYS_RESOURCE_H
 #include <sys/resource.h>
 #endif
 #ifdef HAVE_SYS_STAT_H
 #include <sys/stat.h>
-#endif
-#ifdef HAVE_SYS_TIME_H
-#include <sys/time.h>
 #endif
 #ifdef HAVE_SYS_WAIT_H
 #include <sys/wait.h>
