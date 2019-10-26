--- src/3rdparty/chromium/v8/src/trap-handler/handler-inside-posix.h.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/v8/src/trap-handler/handler-inside-posix.h
@@ -12,7 +12,7 @@ namespace v8 {
 namespace internal {
 namespace trap_handler {
 
-#if V8_OS_LINUX
+#if defined(V8_OS_LINUX) || defined(V8_OS_FREEBSD)
 constexpr int kOobSignal = SIGSEGV;
 #elif V8_OS_MACOSX
 constexpr int kOobSignal = SIGBUS;
