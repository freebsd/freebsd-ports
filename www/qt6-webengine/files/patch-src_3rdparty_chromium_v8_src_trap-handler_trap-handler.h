--- src/3rdparty/chromium/v8/src/trap-handler/trap-handler.h.orig	2022-04-21 18:48:31 UTC
+++ src/3rdparty/chromium/v8/src/trap-handler/trap-handler.h
@@ -20,7 +20,7 @@ namespace trap_handler {
 // X64 on Linux, Windows, MacOS, FreeBSD.
 #if V8_HOST_ARCH_X64 && V8_TARGET_ARCH_X64 &&                        \
     ((V8_OS_LINUX && !V8_OS_ANDROID) || V8_OS_WIN || V8_OS_DARWIN || \
-     V8_OS_FREEBSD)
+     V8_OS_FREEBSD || V8_OS_OPENBSD)
 #define V8_TRAP_HANDLER_SUPPORTED true
 // Arm64 (non-simulator) on Mac.
 #elif V8_TARGET_ARCH_ARM64 && V8_HOST_ARCH_ARM64 && V8_OS_DARWIN
