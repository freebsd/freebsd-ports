--- dialects/freebsd/dnode2.c.orig	2019-05-08 00:32:25.000000000 -0700
+++ dialects/freebsd/dnode2.c	2020-01-05 20:22:25.621138000 -0800
@@ -49,7 +49,13 @@
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
