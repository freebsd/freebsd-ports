--- third_party/chromium/src/base/debug/debugger_posix.cc.orig
+++ third_party/chromium/src/base/debug/debugger_posix.cc
@@ -137,7 +137,7 @@
 
 #elif defined(OS_FREEBSD)
 
-bool DebugUtil::BeingDebugged() {
+bool BeingDebugged() {
   // TODO(benl): can we determine this under FreeBSD?
   NOTIMPLEMENTED();
   return false;
