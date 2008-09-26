--- fuse_module/fuse_vfsops.c.orig	2008-02-05 00:25:57.000000000 -0500
+++ fuse_module/fuse_vfsops.c	2008-09-26 12:53:33.000000000 -0400
@@ -18,6 +18,7 @@
 #include <sys/namei.h>
 #include <sys/mount.h>
 #include <sys/sysctl.h>
+#include <sys/fcntl.h>
 
 #include "fuse.h"
 #include "fuse_session.h"
@@ -667,7 +668,11 @@
 	if (vp->v_type == VNON) {
 		struct vattr va;
 
-		(void)VOP_GETATTR(vp, &va, td->td_ucred, td);
+		(void)VOP_GETATTR(vp, &va, td->td_ucred
+#if VOP_GETATTR_TAKES_THREAD
+		    , td
+#endif
+		);
 	}
 	*vpp = vp;
 #if _DEBUG2G
