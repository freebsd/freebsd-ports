--- v8/src/trap-handler/handler-inside.cc.orig	2018-08-16 12:03:47.253591000 +0200
+++ v8/src/trap-handler/handler-inside.cc	2018-08-16 12:04:41.967410000 +0200
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
