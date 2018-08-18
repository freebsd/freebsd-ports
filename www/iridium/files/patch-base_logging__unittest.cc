--- base/logging_unittest.cc.orig	2017-06-21 19:47:24.089128000 +0200
+++ base/logging_unittest.cc	2017-06-21 20:02:08.177123000 +0200
@@ -272,7 +272,7 @@
   // need the arch-specific boilerplate below, which is inspired by breakpad.
   // At the same time, on OSX, ucontext.h is deprecated but si_addr works fine.
   uintptr_t crash_addr = 0;
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
   crash_addr = reinterpret_cast<uintptr_t>(info->si_addr);
 #else  // OS_POSIX && !OS_MACOSX
   struct ucontext* context = reinterpret_cast<struct ucontext*>(context_ptr);
