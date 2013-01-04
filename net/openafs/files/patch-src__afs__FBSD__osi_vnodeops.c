--- ./src/afs/FBSD/osi_vnodeops.c.orig	2012-11-06 23:51:56.000000000 -0500
+++ ./src/afs/FBSD/osi_vnodeops.c	2012-11-06 23:54:56.000000000 -0500
@@ -501,7 +501,9 @@
     lockparent = flags & LOCKPARENT;
     wantparent = flags & (LOCKPARENT | WANTPARENT);
 
+#if __FreeBSD_version < 1000021
     cnp->cn_flags |= MPSAFE; /* steel */
+#endif
 
     if (flags & ISDOTDOT)
 	MA_VOP_UNLOCK(dvp, 0, p);
