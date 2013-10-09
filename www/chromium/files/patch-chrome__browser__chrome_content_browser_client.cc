--- chrome/browser/chrome_content_browser_client.cc.orig	2013-09-25 22:01:36.000000000 +0300
+++ chrome/browser/chrome_content_browser_client.cc	2013-09-25 22:11:33.000000000 +0300
@@ -166,7 +166,7 @@
 #include "chrome/browser/chrome_browser_main_posix.h"
 #endif
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID)
 #include "base/linux_util.h"
 #include "chrome/browser/crash_handler_host_linux.h"
 #endif
@@ -480,7 +480,7 @@
   }
 }
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 int GetCrashSignalFD(const CommandLine& command_line) {
   if (command_line.HasSwitch(switches::kExtensionProcess)) {
     ExtensionCrashHandlerHostLinux* crash_handler =
@@ -505,7 +505,7 @@
 
   return -1;
 }
-#endif  // defined(OS_POSIX) && !defined(OS_MACOSX)
+#endif  // defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 
 #if !defined(OS_CHROMEOS)
 GURL GetEffectiveURLForSignin(const GURL& url) {
@@ -1346,7 +1346,7 @@
     command_line->AppendSwitchASCII(switches::kEnableCrashReporter,
                                     child_process_logging::GetClientId());
   }
-#elif defined(OS_POSIX)
+#elif defined(OS_POSIX) && !defined(OS_BSD)
   if (IsCrashReporterEnabled()) {
     command_line->AppendSwitchASCII(switches::kEnableCrashReporter,
         child_process_logging::GetClientId() + "," + base::GetLinuxDistro());
@@ -2461,7 +2461,7 @@
   additional_backends->push_back(new sync_file_system::SyncFileSystemBackend());
 }
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 void ChromeContentBrowserClient::GetAdditionalMappedFilesForChildProcess(
     const CommandLine& command_line,
     int child_process_id,
@@ -2521,7 +2521,7 @@
   }
 #endif  // defined(OS_ANDROID)
 }
-#endif  // defined(OS_POSIX) && !defined(OS_MACOSX)
+#endif  // defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 
 #if defined(OS_WIN)
 const wchar_t* ChromeContentBrowserClient::GetResourceDllName() {
