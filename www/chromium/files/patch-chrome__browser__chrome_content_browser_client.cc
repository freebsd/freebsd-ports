--- ./chrome/browser/chrome_content_browser_client.cc.orig	2014-04-30 22:42:18.000000000 +0200
+++ ./chrome/browser/chrome_content_browser_client.cc	2014-05-04 14:38:46.000000000 +0200
@@ -501,7 +501,7 @@
   }
 }
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 breakpad::CrashHandlerHostLinux* CreateCrashHandlerHost(
     const std::string& process_type) {
   base::FilePath dumps_path;
@@ -557,7 +557,7 @@
 
   return -1;
 }
-#endif  // defined(OS_POSIX) && !defined(OS_MACOSX)
+#endif  // defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 #endif  // !defined(OS_ANDROID)
 
 #if !defined(OS_CHROMEOS)
@@ -1460,7 +1460,7 @@
 
 void ChromeContentBrowserClient::AppendExtraCommandLineSwitches(
     CommandLine* command_line, int child_process_id) {
-#if defined(OS_POSIX)
+#if defined(OS_POSIX) && !defined(OS_BSD)
   if (breakpad::IsCrashReporterEnabled()) {
     std::string enable_crash_reporter;
     GoogleUpdateSettings::GetMetricsId(&enable_crash_reporter);
@@ -2610,7 +2610,7 @@
 #endif
 }
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 void ChromeContentBrowserClient::GetAdditionalMappedFilesForChildProcess(
     const CommandLine& command_line,
     int child_process_id,
@@ -2664,7 +2664,7 @@
   }
 #endif  // defined(OS_ANDROID)
 }
-#endif  // defined(OS_POSIX) && !defined(OS_MACOSX)
+#endif  // defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 
 #if defined(OS_WIN)
 const wchar_t* ChromeContentBrowserClient::GetResourceDllName() {
