--- headless/lib/headless_content_main_delegate.cc.orig	2020-07-07 21:58:16 UTC
+++ headless/lib/headless_content_main_delegate.cc
@@ -317,7 +317,7 @@ void HeadlessContentMainDelegate::InitCrashReporter(
     const base::CommandLine& command_line) {
   if (command_line.HasSwitch(::switches::kDisableBreakpad))
     return;
-#if defined(OS_FUCHSIA)
+#if defined(OS_FUCHSIA) || defined(OS_BSD)
   // TODO(fuchsia): Implement this when crash reporting/Breakpad are available
   // in Fuchsia. (crbug.com/753619)
   NOTIMPLEMENTED();
@@ -346,7 +346,7 @@ void HeadlessContentMainDelegate::InitCrashReporter(
   crash_reporter::InitializeCrashpadWithEmbeddedHandler(
       process_type.empty(), process_type, "", base::FilePath());
 #endif  // defined(HEADLESS_USE_BREAKPAD)
-#endif  // defined(OS_FUCHSIA)
+#endif  // defined(OS_FUCHSIA) || defined(OS_BSD)
 }
 
 
@@ -398,7 +398,7 @@ int HeadlessContentMainDelegate::RunProcess(
   return 0;
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 void SIGTERMProfilingShutdown(int signal) {
   content::Profiling::Stop();
   struct sigaction sigact;
@@ -433,7 +433,7 @@ void HeadlessContentMainDelegate::ZygoteForked() {
   breakpad::InitCrashReporter(process_type);
 #endif
 }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
 // static
 HeadlessContentMainDelegate* HeadlessContentMainDelegate::GetInstance() {
