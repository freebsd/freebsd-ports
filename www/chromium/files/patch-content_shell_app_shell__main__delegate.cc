--- content/shell/app/shell_main_delegate.cc.orig	2022-02-07 13:39:41 UTC
+++ content/shell/app/shell_main_delegate.cc
@@ -211,7 +211,7 @@ void ShellMainDelegate::PreSandboxStartup() {
     // Reporting for sub-processes will be initialized in ZygoteForked.
     if (process_type != switches::kZygoteProcess) {
       crash_reporter::InitializeCrashpad(process_type.empty(), process_type);
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
       crash_reporter::SetFirstChanceExceptionHandler(
           v8::TryHandleWebAssemblyTrapPosix);
 #endif
