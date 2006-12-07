--- cramfsck.c.orig	Wed Nov 29 12:49:40 2006
+++ cramfsck.c	Wed Nov 29 12:51:12 2006
@@ -47,13 +47,14 @@
 #include <stdlib.h>
 #include <errno.h>
 #include <string.h>
-#include <sys/sysmacros.h>
 #include <utime.h>
 #include <sys/ioctl.h>
 #define _LINUX_STRING_H_
-#include <linux/fs.h>
 #include <linux/cramfs_fs.h>
 #include <zlib.h>
+
+#define	BLKGETSIZE	_IO(0x12,96)
+#define	MAP_ANONYMOUS	0x20
 
 /* Exit codes used by fsck-type programs */
 #define FSCK_OK          0	/* No errors */
