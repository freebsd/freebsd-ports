--- v8/src/api/api.cc.orig	2025-08-14 19:12:25 UTC
+++ v8/src/api/api.cc
@@ -159,7 +159,7 @@
 #include "src/objects/intl-objects.h"
 #endif  // V8_INTL_SUPPORT
 
-#if V8_OS_LINUX || V8_OS_DARWIN || V8_OS_FREEBSD
+#if V8_OS_LINUX || V8_OS_DARWIN || V8_OS_FREEBSD || V8_OS_OPENBSD
 #include <signal.h>
 #include <unistd.h>
 
@@ -6479,7 +6479,7 @@ bool v8::V8::Initialize(const int build_config) {
   return true;
 }
 
-#if V8_OS_LINUX || V8_OS_DARWIN
+#if V8_OS_LINUX || V8_OS_DARWIN || V8_OS_FREEBSD || V8_OS_OPENBSD
 bool TryHandleWebAssemblyTrapPosix(int sig_code, siginfo_t* info,
                                    void* context) {
 #if V8_ENABLE_WEBASSEMBLY && V8_TRAP_HANDLER_SUPPORTED
