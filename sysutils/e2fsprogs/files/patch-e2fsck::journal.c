
$FreeBSD$

--- e2fsck/journal.c	2001/07/03 14:35:01	1.1
+++ e2fsck/journal.c	2001/07/03 14:35:13
@@ -13,6 +13,8 @@
  */
 
 #ifdef HAVE_SYS_MOUNT_H
+#include <sys/param.h>
+#include <sys/types.h>
 #include <sys/mount.h>
 #define MNT_FL (MS_MGC_VAL | MS_RDONLY)
 #endif
