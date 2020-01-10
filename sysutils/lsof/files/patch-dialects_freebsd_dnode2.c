--- dialects/freebsd/dnode2.c.orig	2019-05-08 07:32:25 UTC
+++ dialects/freebsd/dnode2.c
@@ -49,7 +49,13 @@ static char *rcsid = "$Id: dnode2.c,v 1.7 2018/02/14 1
  *
  * Note: clang's complaint about VOP_FSYNC can't be avoided.
  */
-#define	VOP_UNLOCK(vp, f)	((void)0)
+#include <sys/param.h>
+#if __FreeBSD_version >= 1300074
+#define VOP_UNLOCK_FLAGS(vp, f) ((void)0)
+#define VOP_UNLOCK(vp)  ((void)0)
+#else
+#define VOP_UNLOCK(vp, f)       ((void)0)
+#endif
 # endif	/* defined(__clang__) */
 
 #define	KLD_MODULE		/* for ARM: prevent "ARM_NARCH is 0 " error */
