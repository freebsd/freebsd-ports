--- chrome/app/chrome_main_delegate.cc.orig	2018-12-12 22:56:02.000000000 +0100
+++ chrome/app/chrome_main_delegate.cc	2019-01-04 00:08:47.109460000 +0100
@@ -99,7 +99,7 @@
 #include "chrome/app/shutdown_signal_handlers_posix.h"
 #endif
 
-#if BUILDFLAG(ENABLE_NACL) && defined(OS_LINUX)
+#if BUILDFLAG(ENABLE_NACL) && defined(OS_LINUX) && !defined(OS_BSD)
 #include "components/nacl/common/nacl_paths.h"
 #include "components/nacl/zygote/nacl_fork_delegate_linux.h"
 #endif
@@ -133,7 +133,7 @@
 #include "v8/include/v8.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/environment.h"
 #endif
 
@@ -233,7 +233,7 @@
 
 #endif  // defined(OS_WIN)
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) && !defined(OS_BSD)
 void AdjustLinuxOOMScore(const std::string& process_type) {
   // Browsers and zygotes should still be killable, but killed last.
   const int kZygoteScore = 0;
@@ -401,7 +401,7 @@
   std::string process_type =
       command_line->GetSwitchValueASCII(switches::kProcessType);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // On Linux, Chrome does not support running multiple copies under different
   // DISPLAYs, so the profile directory can be specified in the environment to
   // support the virtual desktop use-case.
@@ -595,7 +595,7 @@
 #if defined(OS_CHROMEOS)
   chromeos::RegisterPathProvider();
 #endif
-#if BUILDFLAG(ENABLE_NACL) && defined(OS_LINUX)
+#if BUILDFLAG(ENABLE_NACL) && defined(OS_LINUX) && !defined(OS_BSD)
   nacl::RegisterPathProvider();
 #endif
 
@@ -912,7 +912,7 @@
   InitializePDF();
 #endif
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
   // Zygote needs to call InitCrashReporter() in RunZygote().
   if (process_type != service_manager::switches::kZygoteProcess) {
 #if defined(OS_ANDROID)
@@ -928,7 +928,7 @@
     breakpad::InitCrashReporter(process_type);
 #endif  // defined(OS_ANDROID)
   }
-#endif  // defined(OS_POSIX) && !defined(OS_MACOSX)
+#endif  // defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 
   // After all the platform Breakpads have been initialized, store the command
   // line for crash reporting.
@@ -938,7 +938,7 @@
 void ChromeMainDelegate::SandboxInitialized(const std::string& process_type) {
   // Note: If you are adding a new process type below, be sure to adjust the
   // AdjustLinuxOOMScore function too.
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) && !defined(OS_BSD)
   AdjustLinuxOOMScore(process_type);
 #endif
 #if defined(OS_WIN)
