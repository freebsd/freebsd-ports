--- lib/mount_util.h.orig	2015-05-22 09:24:02 UTC
+++ lib/mount_util.h
@@ -16,4 +16,3 @@ int fuse_mnt_umount(const char *progname
 char *fuse_mnt_resolve_path(const char *progname, const char *orig);
 int fuse_mnt_check_empty(const char *progname, const char *mnt,
 			 mode_t rootmode, off_t rootsize);
-int fuse_mnt_check_fuseblk(void);
