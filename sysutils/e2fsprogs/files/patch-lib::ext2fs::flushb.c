
$FreeBSD$

--- lib/ext2fs/flushb.c	2001/07/03 14:28:59	1.1
+++ lib/ext2fs/flushb.c	2001/07/03 14:30:57
@@ -21,6 +21,7 @@
 #include <sys/ioctl.h>
 #endif
 #if HAVE_SYS_MOUNT_H
+#include <sys/param.h>
 #include <sys/mount.h>		/* This may define BLKFLSBUF */
 #endif
 
