--- base/files/file_util_posix.cc.orig	2019-03-17 21:31:57 UTC
+++ base/files/file_util_posix.cc
@@ -407,7 +407,7 @@ bool CopyDirectoryExcl(const FilePath& from_path,
 #endif  // !defined(OS_NACL_NONSFI)
 
 bool CreateLocalNonBlockingPipe(int fds[2]) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   return pipe2(fds, O_CLOEXEC | O_NONBLOCK) == 0;
 #else
   int raw_fds[2];
