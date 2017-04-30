--- base/process/launch.h.orig	2017-04-19 19:06:28 UTC
+++ base/process/launch.h
@@ -138,7 +138,7 @@ struct BASE_EXPORT LaunchOptions {
   // will be the same as its pid.
   bool new_process_group = false;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // If non-zero, start the process using clone(), using flags as provided.
   // Unlike in clone, clone_flags may not contain a custom termination signal
   // that is sent to the parent when the child dies. The termination signal will
@@ -151,7 +151,7 @@ struct BASE_EXPORT LaunchOptions {
 
   // Sets parent process death signal to SIGKILL.
   bool kill_on_parent_death = false;
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 #if defined(OS_POSIX)
   // If not empty, launch the specified executable instead of
