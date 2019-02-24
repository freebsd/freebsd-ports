--- v8/src/trap-handler/handler-inside-posix.h.orig	2019-02-02 10:19:11.070129000 +0100
+++ v8/src/trap-handler/handler-inside-posix.h	2019-02-02 10:19:28.516985000 +0100
@@ -12,7 +12,7 @@
 namespace internal {
 namespace trap_handler {
 
-#if V8_OS_LINUX
+#if defined(V8_OS_LINUX) || defined(V8_OS_FREEBSD)
 constexpr int kOobSignal = SIGSEGV;
 #elif V8_OS_MACOSX
 constexpr int kOobSignal = SIGBUS;
