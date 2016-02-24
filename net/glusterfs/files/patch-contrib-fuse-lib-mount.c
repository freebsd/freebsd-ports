--- contrib/fuse-lib/mount.c.orig	2015-11-08 21:57:46 UTC
+++ contrib/fuse-lib/mount.c
@@ -256,6 +256,7 @@ fuse_mount_sys (const char *mountpoint, 
         build_iovec (&iov, &iovlen, "from", "/dev/fuse", -1);
         build_iovec (&iov, &iovlen, "volname", source, -1);
         build_iovec (&iov, &iovlen, "fd", fdstr, -1);
+	build_iovec (&iov, &iovlen, "allow_other", NULL, -1);
         ret = nmount (iov, iovlen, mountflags);
 #else
         ret = mount (source, mountpoint, fstype, mountflags,
