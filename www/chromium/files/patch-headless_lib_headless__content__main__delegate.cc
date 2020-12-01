--- headless/lib/headless_content_main_delegate.cc.orig	2020-11-13 06:36:44 UTC
+++ headless/lib/headless_content_main_delegate.cc
@@ -323,7 +323,7 @@ void HeadlessContentMainDelegate::InitCrashReporter(
     const base::CommandLine& command_line) {
   if (command_line.HasSwitch(::switches::kDisableBreakpad))
     return;
-#if defined(OS_FUCHSIA)
+#if defined(OS_FUCHSIA) || defined(OS_BSD)
   // TODO(fuchsia): Implement this when crash reporting/Breakpad are available
   // in Fuchsia. (crbug.com/753619)
   NOTIMPLEMENTED();
@@ -352,7 +352,7 @@ void HeadlessContentMainDelegate::InitCrashReporter(
   crash_reporter::InitializeCrashpadWithEmbeddedHandler(
       process_type.empty(), process_type, "", base::FilePath());
 #endif  // defined(HEADLESS_USE_BREAKPAD)
-#endif  // defined(OS_FUCHSIA)
+#endif  // defined(OS_FUCHSIA) || defined(OS_BSD)
 }
 
 
