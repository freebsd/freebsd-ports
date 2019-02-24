--- v8/src/trap-handler/trap-handler.h.orig	2019-02-02 10:48:04.472258000 +0100
+++ v8/src/trap-handler/trap-handler.h	2019-02-02 10:49:11.178676000 +0100
@@ -23,6 +23,8 @@
 #define V8_TRAP_HANDLER_SUPPORTED true
 #elif V8_TARGET_ARCH_X64 && V8_OS_MACOSX
 #define V8_TRAP_HANDLER_SUPPORTED true
+#elif V8_TARGET_ARCH_X64 && V8_OS_FREEBSD
+#define V8_TRAP_HANDLER_SUPPORTED true
 #else
 #define V8_TRAP_HANDLER_SUPPORTED false
 #endif
