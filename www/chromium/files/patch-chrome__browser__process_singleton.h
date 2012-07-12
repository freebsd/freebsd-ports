--- chrome/browser/process_singleton.h.orig	2012-05-30 10:01:59.000000000 +0300
+++ chrome/browser/process_singleton.h	2012-06-05 21:41:51.000000000 +0300
@@ -29,9 +29,9 @@
 #include "base/file_path.h"
 #endif  // defined(OS_POSIX)
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/scoped_temp_dir.h"
-#endif  // defined(OS_LINUX) || defined(OS_OPENBSD)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 class CommandLine;
 class FilePath;
@@ -85,7 +85,7 @@
   NotifyResult NotifyOtherProcessOrCreate(
       const NotificationCallback& notification_callback);
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Exposed for testing.  We use a timeout on Linux, and in tests we want
   // this timeout to be short.
   NotifyResult NotifyOtherProcessWithTimeout(const CommandLine& command_line,
@@ -98,7 +98,7 @@
   void OverrideCurrentPidForTesting(base::ProcessId pid);
   void OverrideKillCallbackForTesting(const base::Callback<void(int)>& callback);
   static void DisablePromptForTesting();
-#endif  // defined(OS_LINUX) || defined(OS_OPENBSD)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 #if defined(OS_WIN) && !defined(USE_AURA)
   // Used in specific cases to let us know that there is an existing instance
@@ -171,7 +171,7 @@
   HWND remote_window_;  // The HWND_MESSAGE of another browser.
   HWND window_;  // The HWND_MESSAGE window.
   bool is_virtualized_;  // Stuck inside Microsoft Softricity VM environment.
-#elif defined(OS_LINUX) || defined(OS_OPENBSD)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   // Return true if the given pid is one of our child processes.
   // Assumes that the current pid is the root of all pids of the current
   // instance.
