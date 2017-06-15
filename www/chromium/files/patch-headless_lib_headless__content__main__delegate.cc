--- headless/lib/headless_content_main_delegate.cc.orig	2017-05-09 19:02:47 UTC
+++ headless/lib/headless_content_main_delegate.cc
@@ -147,7 +147,7 @@ void HeadlessContentMainDelegate::InitCr
   g_headless_crash_client.Pointer()->set_crash_dumps_dir(
       browser_->options()->crash_dumps_dir);
 
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
   if (!browser_->options()->enable_crash_reporter) {
     DCHECK(!breakpad::IsCrashReporterEnabled());
     return;
@@ -156,7 +156,7 @@ void HeadlessContentMainDelegate::InitCr
   if (process_type != switches::kZygoteProcess)
     breakpad::InitCrashReporter(process_type);
 #endif  // defined(HEADLESS_USE_BREAKPAD)
-#endif  // !defined(OS_MACOSX)
+#endif  // !defined(OS_MACOSX) && !defined(OS_BSD)
 }
 
 void HeadlessContentMainDelegate::PreSandboxStartup() {
@@ -170,7 +170,7 @@ void HeadlessContentMainDelegate::PreSan
   if (command_line.HasSwitch(switches::kEnableLogging))
     InitLogging(command_line);
 #endif
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
   InitCrashReporter(command_line);
 #endif
   InitializeResourceBundle();
@@ -202,7 +202,7 @@ int HeadlessContentMainDelegate::RunProc
   return 0;
 }
 
-#if !defined(OS_MACOSX) && defined(OS_POSIX) && !defined(OS_ANDROID)
+#if !defined(OS_MACOSX) && defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_BSD)
 void HeadlessContentMainDelegate::ZygoteForked() {
   const base::CommandLine& command_line(
       *base::CommandLine::ForCurrentProcess());
