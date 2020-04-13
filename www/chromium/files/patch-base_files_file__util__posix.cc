--- base/files/file_util_posix.cc.orig	2020-02-03 21:52:37 UTC
+++ base/files/file_util_posix.cc
@@ -411,7 +411,7 @@ bool CreatePipe(ScopedFD* read_fd, ScopedFD* write_fd,
 }
 
 bool CreateLocalNonBlockingPipe(int fds[2]) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   return pipe2(fds, O_CLOEXEC | O_NONBLOCK) == 0;
 #else
   int raw_fds[2];
