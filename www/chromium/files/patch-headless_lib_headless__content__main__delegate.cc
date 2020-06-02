--- headless/lib/headless_content_main_delegate.cc.orig	2020-05-13 18:40:32 UTC
+++ headless/lib/headless_content_main_delegate.cc
@@ -322,7 +322,7 @@ void HeadlessContentMainDelegate::InitCrashReporter(
     const base::CommandLine& command_line) {
   if (command_line.HasSwitch(::switches::kDisableBreakpad))
     return;
-#if defined(OS_FUCHSIA)
+#if defined(OS_FUCHSIA) || defined(OS_BSD)
   // TODO(fuchsia): Implement this when crash reporting/Breakpad are available
   // in Fuchsia. (crbug.com/753619)
   NOTIMPLEMENTED();
@@ -351,7 +351,7 @@ void HeadlessContentMainDelegate::InitCrashReporter(
   crash_reporter::InitializeCrashpadWithEmbeddedHandler(
       process_type.empty(), process_type, "", base::FilePath());
 #endif  // defined(HEADLESS_USE_BREAKPAD)
-#endif  // defined(OS_FUCHSIA)
+#endif  // defined(OS_FUCHSIA) || defined(OS_BSD)
 }
 
 
@@ -405,7 +405,7 @@ int HeadlessContentMainDelegate::RunProcess(
 }
 #endif  // !defined(CHROME_MULTIPLE_DLL_CHILD)
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 void SIGTERMProfilingShutdown(int signal) {
   content::Profiling::Stop();
   struct sigaction sigact;
@@ -440,7 +440,7 @@ void HeadlessContentMainDelegate::ZygoteForked() {
   breakpad::InitCrashReporter(process_type);
 #endif
 }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 // static
 HeadlessContentMainDelegate* HeadlessContentMainDelegate::GetInstance() {
