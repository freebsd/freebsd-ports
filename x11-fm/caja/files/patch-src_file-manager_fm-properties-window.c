--- src/file-manager/fm-properties-window.c.orig	Mon May 14 20:58:01 2007
+++ src/file-manager/fm-properties-window.c	Mon May 14 20:58:42 2007
@@ -89,9 +89,7 @@
 #if HAVE_SYS_VFS_H
 #include <sys/vfs.h>
 #elif HAVE_SYS_MOUNT_H
-#if HAVE_SYS_PARAM_H
 #include <sys/param.h>
-#endif
 #include <sys/mount.h>
 #endif
 
