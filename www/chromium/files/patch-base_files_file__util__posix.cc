--- base/files/file_util_posix.cc.orig	2020-09-08 19:13:57 UTC
+++ base/files/file_util_posix.cc
@@ -415,7 +415,7 @@ bool CreatePipe(ScopedFD* read_fd, ScopedFD* write_fd,
 }
 
 bool CreateLocalNonBlockingPipe(int fds[2]) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   return pipe2(fds, O_CLOEXEC | O_NONBLOCK) == 0;
 #else
   int raw_fds[2];
