--- src/3rdparty/chromium/base/files/scoped_file.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/base/files/scoped_file.cc
@@ -30,7 +30,7 @@ void ScopedFDCloseTraits::Free(int fd) {
   // a single open directory would bypass the entire security model.
   int ret = IGNORE_EINTR(close(fd));
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_APPLE) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || defined(OS_APPLE) || \
     defined(OS_FUCHSIA) || defined(OS_ANDROID)
   // NB: Some file descriptors can return errors from close() e.g. network
   // filesystems such as NFS and Linux input devices. On Linux, macOS, and
