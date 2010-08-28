--- lib/mount_util.h.orig	2008-02-04 00:24:07.000000000 -0500
+++ lib/mount_util.h	2008-02-04 00:24:20.000000000 -0500
@@ -14,4 +14,3 @@
 char *fuse_mnt_resolve_path(const char *progname, const char *orig);
 int fuse_mnt_check_empty(const char *progname, const char *mnt,
 			 mode_t rootmode, off_t rootsize);
-int fuse_mnt_check_fuseblk(void);
