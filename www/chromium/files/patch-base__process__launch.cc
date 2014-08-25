--- ./base/process/launch.cc.orig	2014-08-20 21:02:41.000000000 +0200
+++ ./base/process/launch.cc	2014-08-22 15:06:24.000000000 +0200
@@ -24,10 +24,10 @@
       fds_to_remap(NULL),
       maximize_rlimits(NULL),
       new_process_group(false)
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
       , clone_flags(0)
       , allow_new_privs(false)
-#endif  // OS_LINUX
+#endif  // OS_LINUX || OS_FREEBSD
 #if defined(OS_CHROMEOS)
       , ctrl_terminal_fd(-1)
 #endif  // OS_CHROMEOS
