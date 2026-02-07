--- v8/src/trap-handler/handler-inside-posix.cc.orig	2025-09-10 13:22:16 UTC
+++ v8/src/trap-handler/handler-inside-posix.cc
@@ -62,6 +62,8 @@ namespace trap_handler {
 #define CONTEXT_REG(reg, REG) &uc->uc_mcontext->__ss.__##reg
 #elif V8_OS_FREEBSD
 #define CONTEXT_REG(reg, REG) &uc->uc_mcontext.mc_##reg
+#elif V8_OS_OPENBSD
+#define CONTEXT_REG(reg, REG) &uc->sc_##reg
 #else
 #error "Unsupported platform."
 #endif
@@ -81,8 +83,12 @@ bool IsKernelGeneratedSignal(siginfo_t* info) {
   // si_code at its default of 0 for signals that don’t originate in hardware.
   // The other conditions are only relevant for Linux.
   return info->si_code > 0 && info->si_code != SI_USER &&
-         info->si_code != SI_QUEUE && info->si_code != SI_TIMER &&
-         info->si_code != SI_ASYNCIO && info->si_code != SI_MESGQ;
+         info->si_code != SI_QUEUE && info->si_code != SI_TIMER
+#ifdef V8_OS_OPENBSD
+         ;
+#else
+         && info->si_code != SI_ASYNCIO && info->si_code != SI_MESGQ;
+#endif
 }
 
 class UnmaskOobSignalScope {
