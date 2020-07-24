--- tools/gn/src/base/files/scoped_file.cc.orig	2020-03-16 18:48:21 UTC
+++ tools/gn/src/base/files/scoped_file.cc
@@ -30,7 +30,7 @@ void ScopedFDCloseTraits::Free(int fd) {
   // a single open directory would bypass the entire security model.
   int ret = IGNORE_EINTR(close(fd));
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_FUCHSIA) || \
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_FUCHSIA) || defined(OS_BSD) || \
     defined(OS_ANDROID)
   // NB: Some file descriptors can return errors from close() e.g. network
   // filesystems such as NFS and Linux input devices. On Linux, macOS, and
