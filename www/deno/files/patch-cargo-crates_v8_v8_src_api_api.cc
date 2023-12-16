--- cargo-crates/v8-0.82.0/v8/src/api/api.cc.orig	2020-06-26 16:28:04 UTC
+++ cargo-crates/v8-0.82.0/v8/src/api/api.cc
@@ -6096,7 +6096,7 @@ bool v8::V8::Initialize(const int build_config) {
   return true;
 }
 
-#if V8_OS_LINUX || V8_OS_DARWIN
+#if V8_OS_LINUX || V8_OS_DARWIN || V8_OS_FREEBSD
 bool TryHandleWebAssemblyTrapPosix(int sig_code, siginfo_t* info,
                                    void* context) {
 #if V8_ENABLE_WEBASSEMBLY && V8_TRAP_HANDLER_SUPPORTED
