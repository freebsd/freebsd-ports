--- base/process/launch.h.orig	2015-04-18 22:29:06.000000000 +0200
+++ base/process/launch.h	2015-04-18 22:30:09.000000000 +0200
@@ -131,7 +131,7 @@
   // will be the same as its pid.
   bool new_process_group;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   // If non-zero, start the process using clone(), using flags as provided.
   // Unlike in clone, clone_flags may not contain a custom termination signal
   // that is sent to the parent when the child dies. The termination signal will
@@ -141,7 +141,7 @@
   // By default, child processes will have the PR_SET_NO_NEW_PRIVS bit set. If
   // true, then this bit will not be set in the new child process.
   bool allow_new_privs;
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_FREEBSD)
 
 #if defined(OS_POSIX)
   // If not empty, change to this directory before execing the new process.
