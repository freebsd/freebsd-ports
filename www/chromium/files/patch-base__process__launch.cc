--- base/process/launch.cc.orig	2015-05-13 18:23:01.000000000 -0400
+++ base/process/launch.cc	2015-05-20 09:12:01.335764000 -0400
@@ -24,11 +24,11 @@
       fds_to_remap(NULL),
       maximize_rlimits(NULL),
       new_process_group(false)
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
       , clone_flags(0)
       , allow_new_privs(false)
       , kill_on_parent_death(false)
-#endif  // OS_LINUX
+#endif  // OS_LINUX || OS_FREEBSD
 #if defined(OS_POSIX)
       , pre_exec_delegate(NULL)
 #endif  // OS_POSIX
