--- content/shell/app/shell_main_delegate.cc.orig	2021-04-14 18:41:03 UTC
+++ content/shell/app/shell_main_delegate.cc
@@ -186,7 +186,7 @@ bool ShellMainDelegate::BasicStartupComplete(int* exit
 
 void ShellMainDelegate::PreSandboxStartup() {
 #if defined(ARCH_CPU_ARM_FAMILY) && \
-    (defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS))
+    (defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD))
   // Create an instance of the CPU class to parse /proc/cpuinfo and cache
   // cpu_brand info.
   base::CPU cpu_info;
@@ -195,7 +195,7 @@ void ShellMainDelegate::PreSandboxStartup() {
 // Disable platform crash handling and initialize the crash reporter, if
 // requested.
 // TODO(crbug.com/753619): Implement crash reporter integration for Fuchsia.
-#if !defined(OS_FUCHSIA)
+#if !defined(OS_FUCHSIA) && !defined(OS_BSD)
   if (base::CommandLine::ForCurrentProcess()->HasSwitch(
           switches::kEnableCrashReporter)) {
     std::string process_type =
@@ -211,7 +211,7 @@ void ShellMainDelegate::PreSandboxStartup() {
 #endif
     }
   }
-#endif  // !defined(OS_FUCHSIA)
+#endif  // !defined(OS_FUCHSIA) && !defined(OS_BSD)
 
   crash_reporter::InitializeCrashKeys();
 
