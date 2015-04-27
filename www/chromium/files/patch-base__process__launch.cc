--- base/process/launch.cc.orig	2015-04-18 22:25:46.000000000 +0200
+++ base/process/launch.cc	2015-04-18 22:26:32.000000000 +0200
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
 #if defined(OS_POSIX)
       , pre_exec_delegate(NULL)
 #endif  // OS_POSIX
