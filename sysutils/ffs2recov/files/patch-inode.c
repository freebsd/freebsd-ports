--- inode.c.orig	2017-04-05 19:51:41 UTC
+++ inode.c
@@ -52,6 +52,10 @@
 #define NO_IN_EXTERNS
 #include "ffs2recov.h"
 
+#ifdef UFS_NDADDR
+#define NDADDR UFS_NDADDR
+#endif
+
 static uint64_t direct_maxblk;		/* Max block # for a direct block.    */
 static uint64_t single_maxblk;		/* Max block # for a single indirect. */
 static uint64_t double_maxblk;		/* Max block # for a double indirect. */
