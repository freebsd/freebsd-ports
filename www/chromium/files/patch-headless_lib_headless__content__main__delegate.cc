--- headless/lib/headless_content_main_delegate.cc.orig	2017-06-05 19:03:08 UTC
+++ headless/lib/headless_content_main_delegate.cc
@@ -159,7 +159,7 @@ void HeadlessContentMainDelegate::InitCrashReporter(
   g_headless_crash_client.Pointer()->set_crash_dumps_dir(
       browser_->options()->crash_dumps_dir);
 
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
   if (!browser_->options()->enable_crash_reporter) {
     DCHECK(!breakpad::IsCrashReporterEnabled());
     return;
@@ -168,7 +168,7 @@ void HeadlessContentMainDelegate::InitCrashReporter(
   if (process_type != switches::kZygoteProcess)
     breakpad::InitCrashReporter(process_type);
 #endif  // defined(HEADLESS_USE_BREAKPAD)
-#endif  // !defined(OS_MACOSX)
+#endif  // !defined(OS_MACOSX) && !defined(OS_BSD)
 }
 
 void HeadlessContentMainDelegate::PreSandboxStartup() {
@@ -182,7 +182,7 @@ void HeadlessContentMainDelegate::PreSandboxStartup() 
   if (command_line.HasSwitch(switches::kEnableLogging))
     InitLogging(command_line);
 #endif
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
   InitCrashReporter(command_line);
 #endif
   InitializeResourceBundle();
@@ -214,7 +214,7 @@ int HeadlessContentMainDelegate::RunProcess(
   return 0;
 }
 
-#if !defined(OS_MACOSX) && defined(OS_POSIX) && !defined(OS_ANDROID)
+#if !defined(OS_MACOSX) && defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_BSD)
 void HeadlessContentMainDelegate::ZygoteForked() {
   const base::CommandLine& command_line(
       *base::CommandLine::ForCurrentProcess());
