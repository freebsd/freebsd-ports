--- chrome/browser/process_singleton.h.orig	2012-01-18 11:12:43.000000000 +0200
+++ chrome/browser/process_singleton.h	2012-01-29 15:27:59.000000000 +0200
@@ -22,9 +22,9 @@
 #include "base/file_path.h"
 #endif  // defined(OS_POSIX)
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/scoped_temp_dir.h"
-#endif  // defined(OS_LINUX) || defined(OS_OPENBSD)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 class CommandLine;
 class FilePath;
@@ -67,7 +67,7 @@
   // instance.
   NotifyResult NotifyOtherProcessOrCreate();
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Exposed for testing.  We use a timeout on Linux, and in tests we want
   // this timeout to be short.
   NotifyResult NotifyOtherProcessWithTimeout(const CommandLine& command_line,
@@ -76,7 +76,7 @@
   NotifyResult NotifyOtherProcessWithTimeoutOrCreate(
       const CommandLine& command_line,
       int timeout_seconds);
-#endif  // defined(OS_LINUX) || defined(OS_OPENBSD)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 #if defined(OS_WIN) && !defined(USE_AURA)
   // Used in specific cases to let us know that there is an existing instance
@@ -151,7 +151,7 @@
   HWND remote_window_;  // The HWND_MESSAGE of another browser.
   HWND window_;  // The HWND_MESSAGE window.
   bool is_virtualized_;  // Stuck inside Microsoft Softricity VM environment.
-#elif defined(OS_LINUX) || defined(OS_OPENBSD)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   // Path in file system to the socket.
   FilePath socket_path_;
 
