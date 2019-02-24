--- chrome/app/chrome_main_delegate.cc.orig	2019-01-30 02:17:41.000000000 +0100
+++ chrome/app/chrome_main_delegate.cc	2019-02-06 19:21:07.067687000 +0100
@@ -101,7 +101,7 @@
 #include "chrome/app/shutdown_signal_handlers_posix.h"
 #endif
 
-#if BUILDFLAG(ENABLE_NACL) && defined(OS_LINUX)
+#if BUILDFLAG(ENABLE_NACL) && defined(OS_LINUX) && !defined(OS_BSD)
 #include "components/nacl/common/nacl_paths.h"
 #include "components/nacl/zygote/nacl_fork_delegate_linux.h"
 #endif
@@ -135,7 +135,7 @@
 #include "v8/include/v8.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/environment.h"
 #endif
 
@@ -235,7 +235,7 @@
 
 #endif  // defined(OS_WIN)
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) && !defined(OS_BSD)
 void AdjustLinuxOOMScore(const std::string& process_type) {
   // Browsers and zygotes should still be killable, but killed last.
   const int kZygoteScore = 0;
@@ -339,7 +339,7 @@
   return false;
 }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 // Show the man page if --help or -h is on the command line.
 void HandleHelpSwitches(const base::CommandLine& command_line) {
   if (command_line.HasSwitch(switches::kHelp) ||
@@ -349,7 +349,7 @@
     PLOG(FATAL) << "execlp failed";
   }
 }
-#endif  // defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#endif  // (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 
 #if !defined(OS_MACOSX) && !defined(OS_ANDROID)
 void SIGTERMProfilingShutdown(int signal) {
@@ -403,7 +403,7 @@
   std::string process_type =
       command_line->GetSwitchValueASCII(switches::kProcessType);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // On Linux, Chrome does not support running multiple copies under different
   // DISPLAYs, so the profile directory can be specified in the environment to
   // support the virtual desktop use-case.
@@ -585,7 +585,7 @@
     *exit_code = 0;
     return true;  // Got a --version switch; exit with a success error code.
   }
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   // This will directly exit if the user asked for help.
   HandleHelpSwitches(command_line);
 #endif
@@ -609,7 +609,7 @@
 #if defined(OS_CHROMEOS)
   chromeos::RegisterPathProvider();
 #endif
-#if BUILDFLAG(ENABLE_NACL) && defined(OS_LINUX)
+#if BUILDFLAG(ENABLE_NACL) && defined(OS_LINUX) && !defined(OS_BSD)
   nacl::RegisterPathProvider();
 #endif
 
@@ -925,7 +925,7 @@
   InitializePDF();
 #endif
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
   // Zygote needs to call InitCrashReporter() in RunZygote().
   if (process_type != service_manager::switches::kZygoteProcess) {
 #if defined(OS_ANDROID)
@@ -941,7 +941,7 @@
     breakpad::InitCrashReporter(process_type);
 #endif  // defined(OS_ANDROID)
   }
-#endif  // defined(OS_POSIX) && !defined(OS_MACOSX)
+#endif  // defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 
   // After all the platform Breakpads have been initialized, store the command
   // line for crash reporting.
@@ -951,7 +951,7 @@
 void ChromeMainDelegate::SandboxInitialized(const std::string& process_type) {
   // Note: If you are adding a new process type below, be sure to adjust the
   // AdjustLinuxOOMScore function too.
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) && !defined(OS_BSD)
   AdjustLinuxOOMScore(process_type);
 #endif
 #if defined(OS_WIN)
