--- v8/src/trap-handler/handler-inside-posix.cc.orig	2019-02-02 10:20:15.963337000 +0100
+++ v8/src/trap-handler/handler-inside-posix.cc	2019-02-02 10:41:12.897011000 +0100
@@ -27,7 +27,7 @@
 
 #include <signal.h>
 
-#ifdef V8_OS_LINUX
+#if defined(V8_OS_LINUX) || defined(V8_OS_FREEBSD)
 #include <ucontext.h>
 #elif V8_OS_MACOSX
 #include <sys/ucontext.h>
@@ -109,6 +109,8 @@
     auto* context_rip = &uc->uc_mcontext.gregs[REG_RIP];
 #elif V8_OS_MACOSX
     auto* context_rip = &uc->uc_mcontext->__ss.__rip;
+#elif V8_OS_FREEBSD
+    auto* context_rip = &uc->uc_mcontext.mc_rip;
 #else
 #error Unsupported platform
 #endif
