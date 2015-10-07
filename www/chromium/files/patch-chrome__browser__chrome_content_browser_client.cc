--- chrome/browser/chrome_content_browser_client.cc.orig	2015-09-01 16:10:41.000000000 -0400
+++ chrome/browser/chrome_content_browser_client.cc	2015-09-03 09:43:02.602298000 -0400
@@ -444,7 +444,7 @@
   return false;
 }
 
-#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX) && !defined(OS_BSD)
 breakpad::CrashHandlerHostLinux* CreateCrashHandlerHost(
     const std::string& process_type) {
   base::FilePath dumps_path;
@@ -501,7 +501,7 @@
 
   return -1;
 }
-#endif  // defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX)
+#endif  // defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX) && !defined(OS_BSD)
 
 void SetApplicationLocaleOnIOThread(const std::string& locale) {
   DCHECK(BrowserThread::CurrentlyOn(BrowserThread::IO));
@@ -1246,7 +1246,7 @@
     command_line->AppendSwitchASCII(switches::kMetricsClientID,
                                     client_info->client_id);
   }
-#elif defined(OS_POSIX)
+#elif defined(OS_POSIX) && !defined(OS_BSD)
   if (breakpad::IsCrashReporterEnabled()) {
     scoped_ptr<metrics::ClientInfo> client_info =
         GoogleUpdateSettings::LoadMetricsClientInfo();
@@ -2332,7 +2332,7 @@
   PathService::Get(base::DIR_ANDROID_APP_DATA, &app_data_path);
   DCHECK(!app_data_path.empty());
 }
-#elif defined(OS_POSIX) && !defined(OS_MACOSX)
+#elif defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 void ChromeContentBrowserClient::GetAdditionalMappedFilesForChildProcess(
     const base::CommandLine& command_line,
     int child_process_id,
