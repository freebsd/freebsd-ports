--- src/tools/vfs/vfs_daemon.h.orig	2026-08-01 18:29:37 UTC
+++ src/tools/vfs/vfs_daemon.h
@@ -17,7 +17,13 @@
 
 
 #define VFS_DEFAULT_MOUNTPOINT_DIR "/tmp/ucx"
-#define VFS_FUSE_MOUNT_PROG        "fusermount3"
+#ifdef __FreeBSD__
+#  define VFS_FUSE_MOUNT_PROG   "/sbin/mount_fusefs"
+#  define VFS_FUSE_UNMOUNT_PROG "/sbin/umount"
+#else
+#  define VFS_FUSE_MOUNT_PROG   "fusermount3"
+#  define VFS_FUSE_UNMOUNT_PROG "fusermount3"
+#endif
 
 
 enum {
