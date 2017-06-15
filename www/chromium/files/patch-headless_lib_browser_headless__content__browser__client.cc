--- headless/lib/browser/headless_content_browser_client.cc.orig	2017-05-09 19:02:47 UTC
+++ headless/lib/browser/headless_content_browser_client.cc
@@ -171,7 +171,7 @@ void HeadlessContentBrowserClient::GetQu
       callback);
 }
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 void HeadlessContentBrowserClient::GetAdditionalMappedFilesForChildProcess(
     const base::CommandLine& command_line,
     int child_process_id,
@@ -182,7 +182,7 @@ void HeadlessContentBrowserClient::GetAd
     mappings->Share(kCrashDumpSignal, crash_signal_fd);
 #endif  // defined(HEADLESS_USE_BREAKPAD)
 }
-#endif  // defined(OS_POSIX) && !defined(OS_MACOSX)
+#endif  // defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 
 void HeadlessContentBrowserClient::AppendExtraCommandLineSwitches(
     base::CommandLine* command_line,
