--- encfs/encfs.h.orig	2015-03-24 20:45:16 UTC
+++ encfs/encfs.h
@@ -74,6 +74,7 @@ int encfs_chown(const char *path, uid_t 
 int encfs_truncate(const char *path, off_t size);
 int encfs_ftruncate(const char *path, off_t size, struct fuse_file_info *fi);
 int encfs_utime(const char *path, struct utimbuf *buf);
+int encfs_create(const char *path, mode_t mode, struct fuse_file_info *info);
 int encfs_open(const char *path, struct fuse_file_info *info);
 int encfs_release(const char *path, struct fuse_file_info *info);
 int encfs_read(const char *path, char *buf, size_t size, off_t offset,
