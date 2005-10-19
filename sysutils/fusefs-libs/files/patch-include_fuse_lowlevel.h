--- include/fuse_lowlevel.h.orig	Mon Oct  3 16:12:50 2005
+++ include/fuse_lowlevel.h	Sun Oct  9 22:05:09 2005
@@ -18,7 +18,12 @@
 #include <utime.h>
 #include <sys/types.h>
 #include <sys/stat.h>
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#include <sys/mount.h>
+#else
 #include <sys/statfs.h>
+#endif
 #include <sys/uio.h>
 
 #ifdef __cplusplus
