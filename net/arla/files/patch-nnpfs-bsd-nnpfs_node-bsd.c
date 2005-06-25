--- nnpfs/bsd/nnpfs_node-bsd.c.orig	Sat Jun 25 15:17:37 2005
+++ nnpfs/bsd/nnpfs_node-bsd.c	Sat Jun 25 15:19:32 2005
@@ -39,7 +39,11 @@
 
 RCSID("$Id: nnpfs_node-bsd.c,v 1.84 2005/01/30 22:42:15 lha Exp $");
 
+#if defined(__FreeBSD__) && __FreeBSD_version > 600006
+extern struct vop_vector *nnpfs_vnodeop_p;
+#else
 extern vop_t **nnpfs_vnodeop_p;
+#endif
 
 #ifndef LK_NOPAUSE
 #define LK_NOPAUSE 0
