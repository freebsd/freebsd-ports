--- nnpfs/bsd/nnpfs_message.c.orig	Sat Jun 25 11:50:04 2005
+++ nnpfs/bsd/nnpfs_message.c	Sat Jun 25 11:51:06 2005
@@ -40,6 +40,7 @@
 #include <nnpfs/nnpfs_vfsops.h>
 #include <nnpfs/nnpfs_vnodeops.h>
 #include <nnpfs/nnpfs_dev.h>
+#include <sys/param.h>
 
 RCSID("$Id: nnpfs_message.c,v 1.96 2004/12/22 19:37:45 lha Exp $");
 
@@ -336,7 +337,11 @@
 	nnpfs_dnlc_purge(vp);
     if (vp->v_usecount == 0) {
 	NNPFSDEB(XDEBVNOPS, ("nnpfs_message_invalidnode: vrecycle\n"));
+#if __FreeBSD_version > 600006
+	vrecycle(vp, p);
+#else
 	vrecycle(vp, 0, p);
+#endif
     }
 
     return 0;
