--- dialects/freebsd/dnode2.c.orig	2016-09-22 20:02:53 UTC
+++ dialects/freebsd/dnode2.c
@@ -51,7 +51,7 @@ static char *rcsid = "$Id: dnode2.c,v 1.
  */
 #define	VOP_UNLOCK(vp, f)	((void)0)
 # endif	/* defined(__clang__) */
-
+#define KLD_MODULE
 #include <sys/zfs_znode.h>
 #undef	_KERNEL
 
