--- chrome/app/chrome_main_delegate.cc.orig	2017-06-05 19:03:01 UTC
+++ chrome/app/chrome_main_delegate.cc
@@ -89,7 +89,7 @@
 #include "chrome/app/chrome_crash_reporter_client.h"
 #endif
 
-#if !defined(DISABLE_NACL) && defined(OS_LINUX)
+#if !defined(DISABLE_NACL) && defined(OS_LINUX) && !defined(OS_BSD)
 #include "components/nacl/common/nacl_paths.h"
 #include "components/nacl/zygote/nacl_fork_delegate_linux.h"
 #endif
@@ -117,11 +117,11 @@
 #include "ui/base/x/x11_util.h"  // nogncheck
 #endif
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 #include "components/crash/content/app/breakpad_linux.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/environment.h"
 #endif
 
@@ -164,7 +164,7 @@ base::LazyInstance<ChromeContentBrowserClient>::Destru
     g_chrome_content_browser_client = LAZY_INSTANCE_INITIALIZER;
 #endif
 
-#if defined(OS_POSIX)
+#if defined(OS_POSIX) && !defined(OS_BSD)
 base::LazyInstance<ChromeCrashReporterClient>::Leaky g_chrome_crash_client =
     LAZY_INSTANCE_INITIALIZER;
 #endif
@@ -284,7 +284,7 @@ void AdjustLinuxOOMScore(const std::string& process_ty
 // and resources loaded.
 bool SubprocessNeedsResourceBundle(const std::string& process_type) {
   return
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
       // The zygote process opens the resources for the renderers.
       process_type == switches::kZygoteProcess ||
 #endif
@@ -336,7 +336,7 @@ void HandleHelpSwitches(const base::CommandLine& comma
 }
 #endif
 
-#if !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
 void SIGTERMProfilingShutdown(int signal) {
   Profiling::Stop();
   struct sigaction sigact;
@@ -403,7 +403,7 @@ void InitializeUserDataDir(base::CommandLine* command_
   std::string process_type =
       command_line->GetSwitchValueASCII(switches::kProcessType);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // On Linux, Chrome does not support running multiple copies under different
   // DISPLAYs, so the profile directory can be specified in the environment to
   // support the virtual desktop use-case.
@@ -596,7 +596,7 @@ bool ChromeMainDelegate::BasicStartupComplete(int* exi
       std::string format_str =
           command_line.GetSwitchValueASCII(switches::kDiagnosticsFormat);
       if (format_str == "machine") {
-        format = diagnostics::DiagnosticsWriter::MACHINE;
+        format = diagnostics::DiagnosticsWriter::THEMACHINE;
       } else if (format_str == "log") {
         format = diagnostics::DiagnosticsWriter::LOG;
       } else {
@@ -646,7 +646,7 @@ bool ChromeMainDelegate::BasicStartupComplete(int* exi
       std::string format_str =
           command_line.GetSwitchValueASCII(switches::kDiagnosticsFormat);
       if (format_str == "machine") {
-        format = diagnostics::DiagnosticsWriter::MACHINE;
+        format = diagnostics::DiagnosticsWriter::THEMACHINE;
       } else if (format_str == "human") {
         format = diagnostics::DiagnosticsWriter::HUMAN;
       } else {
@@ -758,7 +758,7 @@ void ChromeMainDelegate::PreSandboxStartup() {
   std::string process_type =
       command_line.GetSwitchValueASCII(switches::kProcessType);
 
-#if defined(OS_POSIX)
+#if defined(OS_POSIX) && !defined(OS_BSD)
   crash_reporter::SetCrashReporterClient(g_chrome_crash_client.Pointer());
 #endif
 
@@ -888,7 +888,7 @@ void ChromeMainDelegate::PreSandboxStartup() {
   chrome::InitializePDF();
 #endif
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
   // Zygote needs to call InitCrashReporter() in RunZygote().
   if (process_type != switches::kZygoteProcess) {
 #if defined(OS_ANDROID)
@@ -903,7 +903,7 @@ void ChromeMainDelegate::PreSandboxStartup() {
     breakpad::InitCrashReporter(process_type);
 #endif  // defined(OS_ANDROID)
   }
-#endif  // defined(OS_POSIX) && !defined(OS_MACOSX)
+#endif  // defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 
   // After all the platform Breakpads have been initialized, store the command
   // line for crash reporting.
@@ -1009,7 +1009,7 @@ bool ChromeMainDelegate::DelaySandboxInitialization(
 #endif
   return process_type == switches::kRelauncherProcess;
 }
-#elif defined(OS_POSIX) && !defined(OS_ANDROID)
+#elif defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_BSD)
 void ChromeMainDelegate::ZygoteStarting(
     std::vector<std::unique_ptr<content::ZygoteForkDelegate>>* delegates) {
 #if defined(OS_CHROMEOS)
