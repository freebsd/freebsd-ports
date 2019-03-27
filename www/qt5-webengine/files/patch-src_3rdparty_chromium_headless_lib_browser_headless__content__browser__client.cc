--- src/3rdparty/chromium/headless/lib/browser/headless_content_browser_client.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/headless/lib/browser/headless_content_browser_client.cc
@@ -205,7 +205,7 @@ void HeadlessContentBrowserClient::GetQuotaSettings(
       partition->GetPath(), context->IsOffTheRecord(), std::move(callback));
 }
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 void HeadlessContentBrowserClient::GetAdditionalMappedFilesForChildProcess(
     const base::CommandLine& command_line,
     int child_process_id,
@@ -216,7 +216,7 @@ void HeadlessContentBrowserClient::GetAdditionalMapped
     mappings->Share(service_manager::kCrashDumpSignal, crash_signal_fd);
 #endif  // defined(HEADLESS_USE_BREAKPAD)
 }
-#endif  // defined(OS_POSIX) && !defined(OS_MACOSX)
+#endif  // defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 
 void HeadlessContentBrowserClient::AppendExtraCommandLineSwitches(
     base::CommandLine* command_line,
