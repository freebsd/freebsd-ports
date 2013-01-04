--- ./src/afs/FBSD/osi_misc.c.orig	2012-11-06 23:51:43.000000000 -0500
+++ ./src/afs/FBSD/osi_misc.c	2012-11-06 23:54:49.000000000 -0500
@@ -37,7 +37,9 @@
 	flags |= FOLLOW;
     else
 	flags |= NOFOLLOW;
+#if __FreeBSD_version < 1000021
     flags |= MPSAFE; /* namei must take Giant if needed */
+#endif
     NDINIT(&n, LOOKUP, flags, seg, aname, curthread);
     if ((error = namei(&n)) != 0) {
 	if (glocked)
