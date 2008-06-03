--- src/fs.c.orig	2008-05-26 11:45:37.000000000 -0400
+++ src/fs.c	2008-05-26 11:48:35.000000000 -0400
@@ -45,6 +45,9 @@
 #ifdef HAVE_SYS_MOUNT_H
 #include <sys/mount.h>
 #endif
+#if defined(HAVE_SYS_PARAM_H) && defined(HAVE_SYS_MOUNT_H)
+#define HAVE_STRUCT_STATFS_F_FSTYPENAME
+#endif
 
 #ifndef HAVE_STRUCT_STATFS_F_FSTYPENAME
 #include <mntent.h>
