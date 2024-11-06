--- v8/src/base/sys-info.cc.orig	2024-11-04 08:56:03 UTC
+++ v8/src/base/sys-info.cc
@@ -36,7 +36,7 @@ namespace base {
 // static
 int SysInfo::NumberOfProcessors() {
 #if V8_OS_OPENBSD
-  int mib[2] = {CTL_HW, HW_NCPU};
+  int mib[2] = {CTL_HW, HW_NCPUONLINE};
   int ncpu = 0;
   size_t len = sizeof(ncpu);
   if (sysctl(mib, arraysize(mib), &ncpu, &len, nullptr, 0) != 0) {
