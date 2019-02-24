--- v8/src/api.cc.orig	2019-02-06 23:49:54.462307000 +0100
+++ v8/src/api.cc	2019-02-06 23:50:45.414499000 +0100
@@ -105,7 +105,7 @@
 #include "src/wasm/wasm-result.h"
 #include "src/wasm/wasm-serialization.h"
 
-#if V8_OS_LINUX || V8_OS_MACOSX
+#if V8_OS_LINUX || V8_OS_MACOSX || V8_OS_OPENBSD || V8_OS_FREEBSD
 #include <signal.h>
 #include "src/trap-handler/handler-inside-posix.h"
 #endif
@@ -5885,7 +5885,7 @@
   return true;
 }
 
-#if V8_OS_LINUX || V8_OS_MACOSX
+#if V8_OS_LINUX || V8_OS_MACOSX || V8_OS_OPENBSD || V8_OS_FREEBSD
 bool TryHandleWebAssemblyTrapPosix(int sig_code, siginfo_t* info,
                                    void* context) {
 #if V8_TARGET_ARCH_X64 && !V8_OS_ANDROID
