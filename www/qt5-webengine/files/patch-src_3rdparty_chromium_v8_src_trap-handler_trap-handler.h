--- src/3rdparty/chromium/v8/src/trap-handler/trap-handler.h.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/v8/src/trap-handler/trap-handler.h
@@ -23,6 +23,8 @@ namespace trap_handler {
 #define V8_TRAP_HANDLER_SUPPORTED true
 #elif V8_TARGET_ARCH_X64 && V8_OS_MACOSX
 #define V8_TRAP_HANDLER_SUPPORTED true
+#elif V8_TARGET_ARCH_X64 && V8_OS_FREEBSD
+#define V8_TRAP_HANDLER_SUPPORTED true
 #else
 #define V8_TRAP_HANDLER_SUPPORTED false
 #endif
