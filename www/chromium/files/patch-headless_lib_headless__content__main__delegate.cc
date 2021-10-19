--- headless/lib/headless_content_main_delegate.cc.orig	2021-09-14 01:51:58 UTC
+++ headless/lib/headless_content_main_delegate.cc
@@ -325,7 +325,7 @@ void HeadlessContentMainDelegate::InitCrashReporter(
     const base::CommandLine& command_line) {
   if (command_line.HasSwitch(::switches::kDisableBreakpad))
     return;
-#if defined(OS_FUCHSIA)
+#if defined(OS_FUCHSIA) || defined(OS_BSD)
   // TODO(crbug.com/1226159): Implement this when crash reporting/Breakpad are
   // available in Fuchsia.
   NOTIMPLEMENTED();
