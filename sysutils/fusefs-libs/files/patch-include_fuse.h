--- include/fuse.h.orig	Mon Oct  3 16:12:50 2005
+++ include/fuse.h	Sun Oct  9 22:05:09 2005
@@ -20,7 +20,12 @@
 
 #include <sys/types.h>
 #include <sys/stat.h>
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#include <sys/mount.h>
+#else
 #include <sys/statfs.h>
+#endif
 #include <utime.h>
 
 #ifdef __cplusplus
