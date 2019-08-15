--- base/logging_unittest.cc.orig	2019-07-24 18:58:02 UTC
+++ base/logging_unittest.cc
@@ -444,7 +444,7 @@ void CheckCrashTestSighandler(int, siginfo_t* info, vo
   // need the arch-specific boilerplate below, which is inspired by breakpad.
   // At the same time, on OSX, ucontext.h is deprecated but si_addr works fine.
   uintptr_t crash_addr = 0;
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
   crash_addr = reinterpret_cast<uintptr_t>(info->si_addr);
 #else  // OS_POSIX && !OS_MACOSX
   ucontext_t* context = reinterpret_cast<ucontext_t*>(context_ptr);
