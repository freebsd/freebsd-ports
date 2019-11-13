--- v8/src/api/api.cc.orig	2019-10-21 19:09:21 UTC
+++ v8/src/api/api.cc
@@ -111,7 +111,7 @@
 #include "src/wasm/wasm-result.h"
 #include "src/wasm/wasm-serialization.h"
 
-#if V8_OS_LINUX || V8_OS_MACOSX
+#if V8_OS_LINUX || V8_OS_MACOSX || V8_OS_OPENBSD || V8_OS_FREEBSD
 #include <signal.h>
 #include "include/v8-wasm-trap-handler-posix.h"
 #include "src/trap-handler/handler-inside-posix.h"
@@ -5573,7 +5573,7 @@ bool v8::V8::Initialize() {
   return true;
 }
 
-#if V8_OS_LINUX || V8_OS_MACOSX
+#if V8_OS_LINUX || V8_OS_MACOSX || V8_OS_OPENBSD || V8_OS_FREEBSD
 bool TryHandleWebAssemblyTrapPosix(int sig_code, siginfo_t* info,
                                    void* context) {
 #if V8_TARGET_ARCH_X64 && !V8_OS_ANDROID
