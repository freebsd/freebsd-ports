--- ./chrome/browser/chrome_content_browser_client.cc.orig	2014-08-12 21:01:48.000000000 +0200
+++ ./chrome/browser/chrome_content_browser_client.cc	2014-08-13 09:56:56.000000000 +0200
@@ -492,7 +492,7 @@
   }
 }
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 breakpad::CrashHandlerHostLinux* CreateCrashHandlerHost(
     const std::string& process_type) {
   base::FilePath dumps_path;
@@ -548,7 +548,7 @@
 
   return -1;
 }
-#endif  // defined(OS_POSIX) && !defined(OS_MACOSX)
+#endif  // defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 #endif  // !defined(OS_ANDROID)
 
 #if !defined(OS_CHROMEOS)
@@ -1459,7 +1459,7 @@
 
 void ChromeContentBrowserClient::AppendExtraCommandLineSwitches(
     CommandLine* command_line, int child_process_id) {
-#if defined(OS_POSIX)
+#if defined(OS_POSIX) && !defined(OS_BSD)
   if (breakpad::IsCrashReporterEnabled()) {
     std::string enable_crash_reporter;
     GoogleUpdateSettings::GetMetricsId(&enable_crash_reporter);
@@ -2563,7 +2563,7 @@
 #endif
 }
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 void ChromeContentBrowserClient::GetAdditionalMappedFilesForChildProcess(
     const CommandLine& command_line,
     int child_process_id,
@@ -2617,7 +2617,7 @@
   }
 #endif  // defined(OS_ANDROID)
 }
-#endif  // defined(OS_POSIX) && !defined(OS_MACOSX)
+#endif  // defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 
 #if defined(OS_WIN)
 const wchar_t* ChromeContentBrowserClient::GetResourceDllName() {
