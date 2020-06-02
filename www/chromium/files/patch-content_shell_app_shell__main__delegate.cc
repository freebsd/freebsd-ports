--- content/shell/app/shell_main_delegate.cc.orig	2020-05-13 18:39:43 UTC
+++ content/shell/app/shell_main_delegate.cc
@@ -181,7 +181,7 @@ bool ShellMainDelegate::BasicStartupComplete(int* exit
 }
 
 void ShellMainDelegate::PreSandboxStartup() {
-#if defined(ARCH_CPU_ARM_FAMILY) && (defined(OS_ANDROID) || defined(OS_LINUX))
+#if defined(ARCH_CPU_ARM_FAMILY) && (defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD))
   // Create an instance of the CPU class to parse /proc/cpuinfo and cache
   // cpu_brand info.
   base::CPU cpu_info;
@@ -200,7 +200,7 @@ void ShellMainDelegate::PreSandboxStartup() {
     // Reporting for sub-processes will be initialized in ZygoteForked.
     if (process_type != service_manager::switches::kZygoteProcess) {
       crash_reporter::InitializeCrashpad(process_type.empty(), process_type);
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
       crash_reporter::SetFirstChanceExceptionHandler(
           v8::TryHandleWebAssemblyTrapPosix);
 #endif
