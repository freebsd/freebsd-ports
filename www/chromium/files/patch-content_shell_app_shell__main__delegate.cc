--- content/shell/app/shell_main_delegate.cc.orig	2024-05-21 18:07:39 UTC
+++ content/shell/app/shell_main_delegate.cc
@@ -281,7 +281,7 @@ void ShellMainDelegate::PreSandboxStartup() {
     // Reporting for sub-processes will be initialized in ZygoteForked.
     if (process_type != switches::kZygoteProcess) {
       crash_reporter::InitializeCrashpad(process_type.empty(), process_type);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       crash_reporter::SetFirstChanceExceptionHandler(
           v8::TryHandleWebAssemblyTrapPosix);
 #endif
