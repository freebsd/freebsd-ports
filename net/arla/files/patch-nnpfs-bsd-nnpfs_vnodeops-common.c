--- nnpfs/bsd/nnpfs_vnodeops-common.c.orig	Sat Jun 25 11:52:35 2005
+++ nnpfs/bsd/nnpfs_vnodeops-common.c	Sat Jun 25 11:52:21 2005
@@ -43,6 +43,7 @@
 #include <nnpfs/nnpfs_deb.h>
 #include <nnpfs/nnpfs_syscalls.h>
 #include <nnpfs/nnpfs_vnodeops.h>
+#include <sys/param.h>
 
 RCSID("$Id: nnpfs_vnodeops-common.c,v 1.108 2005/01/08 16:31:43 lha Exp $");
 
@@ -1036,7 +1037,11 @@
     {
 	nnpfs_vfs_unlock(vp, p);
         NNPFSDEB(XDEBVNOPS, ("nnpfs_inactive: vrecycle\n"));
+#if __FreeBSD_version > 600006
+	vrecycle(vp, p);
+#else
         vrecycle(vp, 0, p);
+#endif
     } else {
 	nnpfs_vfs_unlock(vp, p);
 	xn->flags &= ~NNPFS_STALE;
