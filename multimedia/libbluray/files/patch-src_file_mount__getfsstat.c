--- src/file/mount_getfsstat.c.orig	2022-09-19 14:16:13 UTC
+++ src/file/mount_getfsstat.c
@@ -28,6 +28,7 @@
 #include <stdlib.h>
 #include <string.h>
 
+#define __BSD_VISIBLE 1
 #include <sys/types.h>
 #include <sys/stat.h>
 #ifdef HAVE_GETFSSTAT
