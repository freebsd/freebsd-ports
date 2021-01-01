--- base/process/launch.h.orig	2020-02-03 21:52:37 UTC
+++ base/process/launch.h
@@ -180,7 +180,7 @@ struct BASE_EXPORT LaunchOptions {
   bool clear_environment = false;
 #endif  // OS_WIN || OS_POSIX || OS_FUCHSIA
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // If non-zero, start the process using clone(), using flags as provided.
   // Unlike in clone, clone_flags may not contain a custom termination signal
   // that is sent to the parent when the child dies. The termination signal will
@@ -193,7 +193,7 @@ struct BASE_EXPORT LaunchOptions {
 
   // Sets parent process death signal to SIGKILL.
   bool kill_on_parent_death = false;
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 #if defined(OS_MACOSX) && !defined(OS_IOS)
   // Mach ports that will be accessible to the child process. These are not
