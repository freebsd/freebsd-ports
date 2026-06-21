-- Fix build on FreeBSD: use closefrom(3) to close all open file descriptors
-- instead of the Linux-specific SYS_getdents64 syscall and linux_dirent struct.
-- FreeBSD provides closefrom(2) which is async-signal-safe and closes all fds >= lowfd.
--- paddle/fluid/framework/io/shell.cc.orig	2026-06-19 18:59:11 UTC
+++ paddle/fluid/framework/io/shell.cc
@@ -53,6 +53,9 @@ static int close_open_fds_internal() {
 static int close_open_fds_internal() {
 #if defined(_WIN32) || defined(__APPLE__) || defined(PADDLE_ARM)
   return 0;
+#elif defined(__FreeBSD__)
+  closefrom(3);
+  return 0;
 #else
   struct linux_dirent {
     long d_ino = 0;  // NOLINT
