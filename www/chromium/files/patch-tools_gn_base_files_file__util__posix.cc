--- tools/gn/base/files/file_util_posix.cc.orig	2019-12-16 21:58:04 UTC
+++ tools/gn/base/files/file_util_posix.cc
@@ -250,7 +250,7 @@ bool ReplaceFile(const FilePath& from_path,
 }
 
 bool CreateLocalNonBlockingPipe(int fds[2]) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   return pipe2(fds, O_CLOEXEC | O_NONBLOCK) == 0;
 #else
   int raw_fds[2];
