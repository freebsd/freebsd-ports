--- components/gwp_asan/crash_handler/crash_analyzer.cc.orig	2022-02-07 13:39:41 UTC
+++ components/gwp_asan/crash_handler/crash_analyzer.cc
@@ -26,7 +26,7 @@
 #include "third_party/crashpad/crashpad/snapshot/process_snapshot.h"
 #include "third_party/crashpad/crashpad/util/process/process_memory.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
 #include <signal.h>
 #elif defined(OS_APPLE)
 #include <mach/exception_types.h>
@@ -81,7 +81,7 @@ bool CrashAnalyzer::GetExceptionInfo(
 
 crashpad::VMAddress CrashAnalyzer::GetAccessAddress(
     const crashpad::ExceptionSnapshot& exception) {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
   if (exception.Exception() == SIGSEGV || exception.Exception() == SIGBUS)
     return exception.ExceptionAddress();
 #elif defined(OS_APPLE)
