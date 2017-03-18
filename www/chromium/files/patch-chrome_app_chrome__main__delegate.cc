--- chrome/app/chrome_main_delegate.cc.orig	2017-03-09 20:04:27 UTC
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
 
@@ -163,7 +163,7 @@ base::LazyInstance<ChromeContentBrowserC
     LAZY_INSTANCE_INITIALIZER;
 #endif
 
-#if defined(OS_POSIX)
+#if defined(OS_POSIX) && !defined(OS_BSD)
 base::LazyInstance<ChromeCrashReporterClient>::Leaky g_chrome_crash_client =
     LAZY_INSTANCE_INITIALIZER;
 #endif
@@ -280,7 +280,7 @@ static void AdjustLinuxOOMScore(const st
 // and resources loaded.
 bool SubprocessNeedsResourceBundle(const std::string& process_type) {
   return
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
       // The zygote process opens the resources for the renderers.
       process_type == switches::kZygoteProcess ||
 #endif
@@ -332,7 +332,7 @@ void HandleHelpSwitches(const base::Comm
 }
 #endif
 
-#if !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
 void SIGTERMProfilingShutdown(int signal) {
   Profiling::Stop();
   struct sigaction sigact;
@@ -399,7 +399,7 @@ void InitializeUserDataDir(base::Command
   std::string process_type =
       command_line->GetSwitchValueASCII(switches::kProcessType);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // On Linux, Chrome does not support running multiple copies under different
   // DISPLAYs, so the profile directory can be specified in the environment to
   // support the virtual desktop use-case.
@@ -592,7 +592,7 @@ bool ChromeMainDelegate::BasicStartupCom
       std::string format_str =
           command_line.GetSwitchValueASCII(switches::kDiagnosticsFormat);
       if (format_str == "machine") {
-        format = diagnostics::DiagnosticsWriter::MACHINE;
+        format = diagnostics::DiagnosticsWriter::THEMACHINE;
       } else if (format_str == "log") {
         format = diagnostics::DiagnosticsWriter::LOG;
       } else {
@@ -642,7 +642,7 @@ bool ChromeMainDelegate::BasicStartupCom
       std::string format_str =
           command_line.GetSwitchValueASCII(switches::kDiagnosticsFormat);
       if (format_str == "machine") {
-        format = diagnostics::DiagnosticsWriter::MACHINE;
+        format = diagnostics::DiagnosticsWriter::THEMACHINE;
       } else if (format_str == "human") {
         format = diagnostics::DiagnosticsWriter::HUMAN;
       } else {
@@ -754,7 +754,7 @@ void ChromeMainDelegate::PreSandboxStart
   std::string process_type =
       command_line.GetSwitchValueASCII(switches::kProcessType);
 
-#if defined(OS_POSIX)
+#if defined(OS_POSIX) && !defined(OS_BSD)
   crash_reporter::SetCrashReporterClient(g_chrome_crash_client.Pointer());
 #endif
 
@@ -884,7 +884,7 @@ void ChromeMainDelegate::PreSandboxStart
   chrome::InitializePDF();
 #endif
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
   // Zygote needs to call InitCrashReporter() in RunZygote().
   if (process_type != switches::kZygoteProcess) {
 #if defined(OS_ANDROID)
@@ -898,7 +898,7 @@ void ChromeMainDelegate::PreSandboxStart
     breakpad::InitCrashReporter(process_type);
 #endif  // defined(OS_ANDROID)
   }
-#endif  // defined(OS_POSIX) && !defined(OS_MACOSX)
+#endif  // defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 
   // After all the platform Breakpads have been initialized, store the command
   // line for crash reporting.
@@ -1008,7 +1008,7 @@ bool ChromeMainDelegate::DelaySandboxIni
 #endif
   return process_type == switches::kRelauncherProcess;
 }
-#elif defined(OS_POSIX) && !defined(OS_ANDROID)
+#elif defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_BSD)
 void ChromeMainDelegate::ZygoteStarting(
     ScopedVector<content::ZygoteForkDelegate>* delegates) {
 #if defined(OS_CHROMEOS)
