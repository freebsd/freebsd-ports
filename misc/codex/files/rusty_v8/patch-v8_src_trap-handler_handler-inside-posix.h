--- v8/src/trap-handler/handler-inside-posix.h.orig	1970-01-01 00:00:00 UTC
+++ v8/src/trap-handler/handler-inside-posix.h
@@ -13,7 +13,7 @@ namespace trap_handler {
 namespace internal {
 namespace trap_handler {
 
-#if V8_OS_LINUX || V8_OS_FREEBSD
+#if V8_OS_LINUX || V8_OS_FREEBSD || V8_OS_OPENBSD
 constexpr int kOobSignal = SIGSEGV;
 #elif V8_OS_DARWIN
 constexpr int kOobSignal = SIGBUS;
