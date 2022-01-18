--- core/Common/3dParty/v8/v8/src/api/api.cc.orig	2020-12-15 11:23:25 UTC
+++ core/Common/3dParty/v8/v8/src/api/api.cc
@@ -5760,7 +5760,7 @@ bool v8::V8::Initialize(const int build_config) {
   return true;
 }
 
-#if V8_OS_LINUX || V8_OS_MACOSX
+#if V8_OS_LINUX || V8_OS_MACOSX || V8_OS_OPENBSD || V8_OS_FREEBSD
 bool TryHandleWebAssemblyTrapPosix(int sig_code, siginfo_t* info,
                                    void* context) {
 #if V8_TARGET_ARCH_X64 && !V8_OS_ANDROID
