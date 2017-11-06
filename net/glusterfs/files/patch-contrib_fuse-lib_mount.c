--- contrib/fuse-lib/mount.c.orig	2017-06-27 15:25:12 UTC
+++ contrib/fuse-lib/mount.c
@@ -382,6 +382,7 @@ fuse_mount_sys (const char *mountpoint, 
         build_iovec (&iov, &iovlen, "from", "/dev/fuse", -1);
         build_iovec (&iov, &iovlen, "volname", source, -1);
         build_iovec (&iov, &iovlen, "fd", fdstr, -1);
+        build_iovec (&iov, &iovlen, "allow_other", NULL, -1);
         ret = nmount (iov, iovlen, mountflags);
 #else
         ret = mount (source, mountpoint, fstype, mountflags,
