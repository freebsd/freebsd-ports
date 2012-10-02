--- chrome/browser/process_singleton.h.orig	2012-09-25 16:02:18.000000000 +0300
+++ chrome/browser/process_singleton.h	2012-09-29 15:03:27.000000000 +0300
@@ -28,9 +28,9 @@
 #include "base/file_path.h"
 #endif  // defined(OS_POSIX)
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/scoped_temp_dir.h"
-#endif  // defined(OS_LINUX) || defined(OS_OPENBSD)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 class CommandLine;
 class FilePath;
@@ -84,7 +84,7 @@
   NotifyResult NotifyOtherProcessOrCreate(
       const NotificationCallback& notification_callback);
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Exposed for testing.  We use a timeout on Linux, and in tests we want
   // this timeout to be short.
   NotifyResult NotifyOtherProcessWithTimeout(const CommandLine& command_line,
@@ -97,7 +97,7 @@
   void OverrideCurrentPidForTesting(base::ProcessId pid);
   void OverrideKillCallbackForTesting(const base::Callback<void(int)>& callback);
   static void DisablePromptForTesting();
-#endif  // defined(OS_LINUX) || defined(OS_OPENBSD)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 #if defined(OS_WIN) && !defined(USE_AURA)
   // Used in specific cases to let us know that there is an existing instance
@@ -171,7 +171,7 @@
   HWND window_;  // The HWND_MESSAGE window.
   bool is_virtualized_;  // Stuck inside Microsoft Softricity VM environment.
   HANDLE lock_file_;
-#elif defined(OS_LINUX) || defined(OS_OPENBSD)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   // Return true if the given pid is one of our child processes.
   // Assumes that the current pid is the root of all pids of the current
   // instance.
