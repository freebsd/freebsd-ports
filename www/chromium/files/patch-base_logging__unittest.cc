--- base/logging_unittest.cc.orig	2020-11-13 06:36:34 UTC
+++ base/logging_unittest.cc
@@ -29,7 +29,7 @@
 #include "base/posix/eintr_wrapper.h"
 #endif  // OS_POSIX
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
 #include <ucontext.h>
 #endif
 
@@ -559,7 +559,7 @@ void CheckCrashTestSighandler(int, siginfo_t* info, vo
   // need the arch-specific boilerplate below, which is inspired by breakpad.
   // At the same time, on OSX, ucontext.h is deprecated but si_addr works fine.
   uintptr_t crash_addr = 0;
-#if defined(OS_MAC)
+#if defined(OS_MAC) || defined(OS_BSD)
   crash_addr = reinterpret_cast<uintptr_t>(info->si_addr);
 #else  // OS_*
   ucontext_t* context = reinterpret_cast<ucontext_t*>(context_ptr);
