--- base/process/launch.cc.orig	2014-10-10 08:54:09 UTC
+++ base/process/launch.cc
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
