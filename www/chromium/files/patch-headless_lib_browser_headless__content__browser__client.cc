--- headless/lib/browser/headless_content_browser_client.cc.orig	2020-03-16 18:39:51 UTC
+++ headless/lib/browser/headless_content_browser_client.cc
@@ -157,7 +157,7 @@ HeadlessContentBrowserClient::GetGeneratedCodeCacheSet
   return content::GeneratedCodeCacheSettings(true, 0, context->GetPath());
 }
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 void HeadlessContentBrowserClient::GetAdditionalMappedFilesForChildProcess(
     const base::CommandLine& command_line,
     int child_process_id,
@@ -168,7 +168,7 @@ void HeadlessContentBrowserClient::GetAdditionalMapped
     mappings->Share(service_manager::kCrashDumpSignal, crash_signal_fd);
 #endif  // defined(HEADLESS_USE_BREAKPAD)
 }
-#endif  // defined(OS_POSIX) && !defined(OS_MACOSX)
+#endif  // defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 
 void HeadlessContentBrowserClient::AppendExtraCommandLineSwitches(
     base::CommandLine* command_line,
@@ -231,7 +231,7 @@ void HeadlessContentBrowserClient::AppendExtraCommandL
                                             process_type, child_process_id);
   }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Processes may only query perf_event_open with the BPF sandbox disabled.
   if (old_command_line.HasSwitch(::switches::kEnableThreadInstructionCount) &&
       old_command_line.HasSwitch(service_manager::switches::kNoSandbox)) {
