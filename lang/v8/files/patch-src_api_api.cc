--- src/api/api.cc.orig	2021-06-08 16:09:55 UTC
+++ src/api/api.cc
@@ -5764,7 +5764,7 @@ bool v8::V8::Initialize(const int build_config) {
   return true;
 }
 
-#if V8_OS_LINUX || V8_OS_MACOSX
+#if V8_OS_LINUX || V8_OS_MACOSX || V8_OS_OPENBSD || V8_OS_FREEBSD
 bool TryHandleWebAssemblyTrapPosix(int sig_code, siginfo_t* info,
                                    void* context) {
   // When the target code runs on the V8 arm simulator, the trap handler does
