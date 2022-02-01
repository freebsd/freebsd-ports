--- headless/lib/headless_content_main_delegate.cc.orig	2021-12-14 11:45:07 UTC
+++ headless/lib/headless_content_main_delegate.cc
@@ -318,7 +318,7 @@ void HeadlessContentMainDelegate::InitCrashReporter(
     const base::CommandLine& command_line) {
   if (command_line.HasSwitch(::switches::kDisableBreakpad))
     return;
-#if defined(OS_FUCHSIA)
+#if defined(OS_FUCHSIA) || defined(OS_BSD)
   // TODO(crbug.com/1226159): Implement this when crash reporting/Breakpad are
   // available in Fuchsia.
   NOTIMPLEMENTED();
