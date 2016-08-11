--- base/process/launch.h.orig	2016-05-11 19:02:11 UTC
+++ base/process/launch.h
@@ -135,7 +135,7 @@ struct BASE_EXPORT LaunchOptions {
   // will be the same as its pid.
   bool new_process_group;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   // If non-zero, start the process using clone(), using flags as provided.
   // Unlike in clone, clone_flags may not contain a custom termination signal
   // that is sent to the parent when the child dies. The termination signal will
@@ -148,7 +148,7 @@ struct BASE_EXPORT LaunchOptions {
 
   // Sets parent process death signal to SIGKILL.
   bool kill_on_parent_death;
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_FREEBSD)
 
 #if defined(OS_POSIX)
   // If not empty, change to this directory before execing the new process.
