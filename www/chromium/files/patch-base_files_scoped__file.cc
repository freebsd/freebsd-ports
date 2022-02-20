--- base/files/scoped_file.cc.orig	2022-02-07 13:39:41 UTC
+++ base/files/scoped_file.cc
@@ -31,7 +31,7 @@ void ScopedFDCloseTraits::Free(int fd) {
   int ret = IGNORE_EINTR(close(fd));
 
 #if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_APPLE) || \
-    defined(OS_FUCHSIA) || defined(OS_ANDROID)
+    defined(OS_FUCHSIA) || defined(OS_ANDROID) || defined(OS_BSD)
   // NB: Some file descriptors can return errors from close() e.g. network
   // filesystems such as NFS and Linux input devices. On Linux, macOS, and
   // Fuchsia's POSIX layer, errors from close other than EBADF do not indicate
