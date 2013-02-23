--- chrome/browser/process_singleton.h.orig	2012-12-20 10:02:17.000000000 +0200
+++ chrome/browser/process_singleton.h	2013-01-06 21:27:17.000000000 +0200
@@ -24,9 +24,9 @@
 #include "base/threading/non_thread_safe.h"
 #include "ui/gfx/native_widget_types.h"
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/files/scoped_temp_dir.h"
-#endif  // defined(OS_LINUX) || defined(OS_OPENBSD)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 class CommandLine;
 
@@ -114,9 +114,9 @@
   LRESULT WndProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);
 #endif
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
   static void DisablePromptForTesting();
-#endif  // defined(OS_LINUX) || defined(OS_OPENBSD)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
  protected:
   // Notify another process, if available.
@@ -125,7 +125,7 @@
   // On Windows, Create() has to be called before this.
   NotifyResult NotifyOtherProcess();
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Exposed for testing.  We use a timeout on Linux, and in tests we want
   // this timeout to be short.
   NotifyResult NotifyOtherProcessWithTimeout(const CommandLine& command_line,
@@ -138,7 +138,7 @@
   void OverrideCurrentPidForTesting(base::ProcessId pid);
   void OverrideKillCallbackForTesting(
       const base::Callback<void(int)>& callback);
-#endif  // defined(OS_LINUX) || defined(OS_OPENBSD)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
  private:
   typedef std::pair<CommandLine::StringVector, FilePath> DelayedStartupMessage;
@@ -164,7 +164,7 @@
   bool is_virtualized_;  // Stuck inside Microsoft Softricity VM environment.
   HANDLE lock_file_;
   FilePath user_data_dir_;
-#elif defined(OS_LINUX) || defined(OS_OPENBSD)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   // Return true if the given pid is one of our child processes.
   // Assumes that the current pid is the root of all pids of the current
   // instance.
