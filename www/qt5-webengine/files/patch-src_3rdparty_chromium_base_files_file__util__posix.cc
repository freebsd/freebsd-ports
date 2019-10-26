--- src/3rdparty/chromium/base/files/file_util_posix.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/base/files/file_util_posix.cc
@@ -407,7 +407,7 @@ bool CopyDirectoryExcl(const FilePath& from_path,
 #endif  // !defined(OS_NACL_NONSFI)
 
 bool CreateLocalNonBlockingPipe(int fds[2]) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   return pipe2(fds, O_CLOEXEC | O_NONBLOCK) == 0;
 #else
   int raw_fds[2];
