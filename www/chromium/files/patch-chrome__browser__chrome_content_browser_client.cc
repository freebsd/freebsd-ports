--- ./chrome/browser/chrome_content_browser_client.cc.orig	2014-04-24 22:35:13.000000000 +0200
+++ ./chrome/browser/chrome_content_browser_client.cc	2014-04-24 23:23:42.000000000 +0200
@@ -493,7 +493,7 @@
   }
 }
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 breakpad::CrashHandlerHostLinux* CreateCrashHandlerHost(
     const std::string& process_type) {
   base::FilePath dumps_path;
@@ -549,7 +549,7 @@
 
   return -1;
 }
-#endif  // defined(OS_POSIX) && !defined(OS_MACOSX)
+#endif  // defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 #endif  // !defined(OS_ANDROID)
 
 #if !defined(OS_CHROMEOS)
@@ -1449,7 +1449,7 @@
 
 void ChromeContentBrowserClient::AppendExtraCommandLineSwitches(
     CommandLine* command_line, int child_process_id) {
-#if defined(OS_POSIX)
+#if defined(OS_POSIX) && !defined(OS_BSD)
   if (breakpad::IsCrashReporterEnabled()) {
     std::string enable_crash_reporter;
     GoogleUpdateSettings::GetMetricsId(&enable_crash_reporter);
@@ -2587,7 +2587,7 @@
   }
 }
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 void ChromeContentBrowserClient::GetAdditionalMappedFilesForChildProcess(
     const CommandLine& command_line,
     int child_process_id,
@@ -2642,7 +2642,7 @@
   }
 #endif  // defined(OS_ANDROID)
 }
-#endif  // defined(OS_POSIX) && !defined(OS_MACOSX)
+#endif  // defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 
 #if defined(OS_WIN)
 const wchar_t* ChromeContentBrowserClient::GetResourceDllName() {
