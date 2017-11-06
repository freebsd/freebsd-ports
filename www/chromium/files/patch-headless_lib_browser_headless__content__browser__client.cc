--- headless/lib/browser/headless_content_browser_client.cc.orig	2017-06-05 19:03:08 UTC
+++ headless/lib/browser/headless_content_browser_client.cc
@@ -172,7 +172,7 @@ void HeadlessContentBrowserClient::GetQuotaSettings(
       callback);
 }
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 void HeadlessContentBrowserClient::GetAdditionalMappedFilesForChildProcess(
     const base::CommandLine& command_line,
     int child_process_id,
@@ -183,7 +183,7 @@ void HeadlessContentBrowserClient::GetAdditionalMapped
     mappings->Share(kCrashDumpSignal, crash_signal_fd);
 #endif  // defined(HEADLESS_USE_BREAKPAD)
 }
-#endif  // defined(OS_POSIX) && !defined(OS_MACOSX)
+#endif  // defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 
 void HeadlessContentBrowserClient::AppendExtraCommandLineSwitches(
     base::CommandLine* command_line,
