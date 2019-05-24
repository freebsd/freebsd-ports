--- base/process/launch.h.orig	2019-04-30 22:22:28 UTC
+++ base/process/launch.h
@@ -179,7 +179,7 @@ struct BASE_EXPORT LaunchOptions {
   FileHandleMappingVector fds_to_remap;
 #endif  // defined(OS_WIN)
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // If non-zero, start the process using clone(), using flags as provided.
   // Unlike in clone, clone_flags may not contain a custom termination signal
   // that is sent to the parent when the child dies. The termination signal will
@@ -192,7 +192,7 @@ struct BASE_EXPORT LaunchOptions {
 
   // Sets parent process death signal to SIGKILL.
   bool kill_on_parent_death = false;
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 #if defined(OS_MACOSX) && !defined(OS_IOS)
   // Mach ports that will be accessible to the child process. These are not
