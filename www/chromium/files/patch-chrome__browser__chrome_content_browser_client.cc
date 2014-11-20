--- chrome/browser/chrome_content_browser_client.cc.orig	2014-10-10 09:15:30 UTC
+++ chrome/browser/chrome_content_browser_client.cc
@@ -434,7 +434,7 @@
   return false;
 }
 
-#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX) && !defined(OS_BSD)
 breakpad::CrashHandlerHostLinux* CreateCrashHandlerHost(
     const std::string& process_type) {
   base::FilePath dumps_path;
@@ -491,7 +491,7 @@
 
   return -1;
 }
-#endif  // defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX)
+#endif  // defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX) && !defined(OS_BSD)
 
 #if !defined(OS_CHROMEOS)
 GURL GetEffectiveURLForSignin(const GURL& url) {
@@ -1194,7 +1194,7 @@
 
 void ChromeContentBrowserClient::AppendExtraCommandLineSwitches(
     CommandLine* command_line, int child_process_id) {
-#if defined(OS_POSIX)
+#if defined(OS_POSIX) && !defined(OS_BSD)
   if (breakpad::IsCrashReporterEnabled()) {
     scoped_ptr<metrics::ClientInfo> client_info =
         GoogleUpdateSettings::LoadMetricsClientInfo();
@@ -1202,7 +1202,7 @@
                                     client_info ? client_info->client_id
                                                 : std::string());
   }
-#endif  // defined(OS_POSIX)
+#endif  // defined(OS_POSIX) && !defined(OS_BSD)
 
   if (logging::DialogsAreSuppressed())
     command_line->AppendSwitch(switches::kNoErrorDialogs);
@@ -2408,7 +2408,7 @@
   }
 }
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 void ChromeContentBrowserClient::GetAdditionalMappedFilesForChildProcess(
     const CommandLine& command_line,
     int child_process_id,
@@ -2474,7 +2474,7 @@
   }
 #endif  // defined(OS_ANDROID)
 }
-#endif  // defined(OS_POSIX) && !defined(OS_MACOSX)
+#endif  // defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 
 #if defined(OS_WIN)
 const wchar_t* ChromeContentBrowserClient::GetResourceDllName() {
