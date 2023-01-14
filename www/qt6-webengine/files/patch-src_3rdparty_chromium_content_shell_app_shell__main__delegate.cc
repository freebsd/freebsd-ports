--- src/3rdparty/chromium/content/shell/app/shell_main_delegate.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/content/shell/app/shell_main_delegate.cc
@@ -211,7 +211,7 @@ void ShellMainDelegate::PreSandboxStartup() {
     // Reporting for sub-processes will be initialized in ZygoteForked.
     if (process_type != switches::kZygoteProcess) {
       crash_reporter::InitializeCrashpad(process_type.empty(), process_type);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       crash_reporter::SetFirstChanceExceptionHandler(
           v8::TryHandleWebAssemblyTrapPosix);
 #endif
