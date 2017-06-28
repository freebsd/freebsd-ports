--- v8/src/trap-handler/handler-inside.cc.orig	2017-06-27 01:24:28.401955000 +0200
+++ v8/src/trap-handler/handler-inside.cc	2017-06-27 01:25:16.190737000 +0200
@@ -36,11 +36,13 @@
 
 namespace {
 
+#if V8_TRAP_HANDLER_SUPPORTED && V8_OS_LINUX
 bool IsKernelGeneratedSignal(siginfo_t* info) {
   return info->si_code > 0 && info->si_code != SI_USER &&
          info->si_code != SI_QUEUE && info->si_code != SI_TIMER &&
          info->si_code != SI_ASYNCIO && info->si_code != SI_MESGQ;
 }
+#endif
 
 #if V8_TRAP_HANDLER_SUPPORTED
 class SigUnmaskStack {
