--- content/shell/app/shell_main_delegate.cc.orig	2021-09-14 01:51:57 UTC
+++ content/shell/app/shell_main_delegate.cc
@@ -193,7 +193,7 @@ bool ShellMainDelegate::ShouldCreateFeatureList() {
 
 void ShellMainDelegate::PreSandboxStartup() {
 #if defined(ARCH_CPU_ARM_FAMILY) && \
-    (defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS))
+    (defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD))
   // Create an instance of the CPU class to parse /proc/cpuinfo and cache
   // cpu_brand info.
   base::CPU cpu_info;
@@ -202,7 +202,7 @@ void ShellMainDelegate::PreSandboxStartup() {
 // Disable platform crash handling and initialize the crash reporter, if
 // requested.
 // TODO(crbug.com/1226159): Implement crash reporter integration for Fuchsia.
-#if !defined(OS_FUCHSIA)
+#if !defined(OS_FUCHSIA) && !defined(OS_BSD)
   if (base::CommandLine::ForCurrentProcess()->HasSwitch(
           switches::kEnableCrashReporter)) {
     std::string process_type =
@@ -218,7 +218,7 @@ void ShellMainDelegate::PreSandboxStartup() {
 #endif
     }
   }
-#endif  // !defined(OS_FUCHSIA)
+#endif  // !defined(OS_FUCHSIA) && !defined(OS_BSD)
 
   crash_reporter::InitializeCrashKeys();
 
