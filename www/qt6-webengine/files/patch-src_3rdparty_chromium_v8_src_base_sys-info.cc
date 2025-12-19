--- src/3rdparty/chromium/v8/src/base/sys-info.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/v8/src/base/sys-info.cc
@@ -36,7 +36,7 @@ int SysInfo::NumberOfProcessors() {
 // static
 int SysInfo::NumberOfProcessors() {
 #if V8_OS_OPENBSD
-  int mib[2] = {CTL_HW, HW_NCPU};
+  int mib[2] = {CTL_HW, HW_NCPUONLINE};
   int ncpu = 0;
   size_t len = sizeof(ncpu);
   if (sysctl(mib, arraysize(mib), &ncpu, &len, nullptr, 0) != 0) {
