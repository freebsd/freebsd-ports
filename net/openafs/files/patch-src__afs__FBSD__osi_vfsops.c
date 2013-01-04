--- ./src/afs/FBSD/osi_vfsops.c.orig	2012-11-06 23:59:19.000000000 -0500
+++ ./src/afs/FBSD/osi_vfsops.c	2012-11-06 23:55:08.000000000 -0500
@@ -135,7 +135,9 @@
 #if defined(AFS_FBSD61_ENV) && !defined(AFS_FBSD62_ENV)
     MNT_ILOCK(mp);
 #endif
+#if __FreeBSD_version < 1000021
     mp->mnt_kern_flag |= MNTK_MPSAFE; /* solid steel */
+#endif
 #ifndef AFS_FBSD61_ENV
     MNT_ILOCK(mp);
 #endif
