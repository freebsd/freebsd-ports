--- v8/src/trap-handler/handler-inside-posix.cc.orig	2019-03-11 22:08:08 UTC
+++ v8/src/trap-handler/handler-inside-posix.cc
@@ -27,7 +27,7 @@
 
 #include <signal.h>
 
-#ifdef V8_OS_LINUX
+#if defined(V8_OS_LINUX) || defined(V8_OS_FREEBSD)
 #include <ucontext.h>
 #elif V8_OS_MACOSX
 #include <sys/ucontext.h>
@@ -112,6 +112,8 @@ bool TryHandleSignal(int signum, siginfo_t* info, void
     auto* context_rip = &uc->uc_mcontext.gregs[REG_RIP];
 #elif V8_OS_MACOSX
     auto* context_rip = &uc->uc_mcontext->__ss.__rip;
+#elif V8_OS_FREEBSD
+    auto* context_rip = &uc->uc_mcontext.mc_rip;
 #else
 #error Unsupported platform
 #endif
