--- headless/lib/headless_content_main_delegate.cc.orig	2022-02-28 16:54:41 UTC
+++ headless/lib/headless_content_main_delegate.cc
@@ -331,7 +331,7 @@ void HeadlessContentMainDelegate::InitCrashReporter(
   if (process_type != switches::kZygoteProcess) {
     g_headless_crash_client.Pointer()->set_crash_dumps_dir(
         options()->crash_dumps_dir);
-#if !BUILDFLAG(IS_WIN)
+#if !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_BSD)
     crash_reporter::InitializeCrashpad(process_type.empty(), process_type);
 #endif  // !BUILDFLAG(IS_WIN)
     crash_keys::SetSwitchesFromCommandLine(command_line, nullptr);
