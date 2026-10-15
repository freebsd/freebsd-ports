--- base/system/sys_info_openbsd.cc.orig	2026-02-11 09:05:39 UTC
+++ base/system/sys_info_openbsd.cc
@@ -13,6 +13,7 @@
 #include "base/notreached.h"
 #include "base/numerics/safe_conversions.h"
 #include "base/posix/sysctl.h"
+#include "base/strings/string_util.h"
 
 namespace base {
 
@@ -29,9 +30,14 @@ ByteSize AmountOfMemory(int pages_name) {
 
 }  // namespace
 
+// pledge(2)
+ByteSize aofpmem = ByteSize(0);
+uint64_t shmmax = 0;
+char cpumodel[256];
+
 // static
 int SysInfo::NumberOfProcessors() {
-  int mib[] = {CTL_HW, HW_NCPU};
+  int mib[] = {CTL_HW, HW_NCPUONLINE};
   int ncpu;
   size_t size = sizeof(ncpu);
   if (sysctl(mib, std::size(mib), &ncpu, &size, NULL, 0) < 0) {
@@ -41,8 +47,24 @@ int SysInfo::NumberOfProcessors() {
 }
 
 // static
+std::string SysInfo::CPUModelName() {
+  int mib[] = {CTL_HW, HW_MODEL};
+  size_t len = std::size(cpumodel);
+  
+  if (cpumodel[0] == '\0') {
+    if (sysctl(mib, std::size(mib), cpumodel, &len, NULL, 0) < 0)
+      return std::string();
+  }
+ 
+  return std::string(cpumodel, len - 1);
+}
+
+// static
 ByteSize SysInfo::AmountOfTotalPhysicalMemoryImpl() {
-  return AmountOfMemory(_SC_PHYS_PAGES);
+  // pledge(2)
+  if (aofpmem == ByteSize(0))
+    aofpmem = AmountOfMemory(_SC_PHYS_PAGES);
+  return aofpmem;
 }
 
 // static
@@ -57,15 +79,27 @@ uint64_t SysInfo::MaxSharedMemorySize() {
   int mib[] = {CTL_KERN, KERN_SHMINFO, KERN_SHMINFO_SHMMAX};
   size_t limit;
   size_t size = sizeof(limit);
+  // pledge(2)
+  if (shmmax)
+    goto out;
   if (sysctl(mib, std::size(mib), &limit, &size, NULL, 0) < 0) {
     NOTREACHED();
   }
-  return static_cast<uint64_t>(limit);
+  shmmax = static_cast<uint64_t>(limit);
+out:
+  return shmmax;
 }
 
 // static
-std::string SysInfo::CPUModelName() {
-  return StringSysctl({CTL_HW, HW_MODEL}).value();
+SysInfo::HardwareInfo SysInfo::GetHardwareInfoSync() {
+  HardwareInfo info;
+  // Set the manufacturer to "OpenBSD" and the model to
+  // an empty string.
+  info.manufacturer = "OpenBSD";
+  info.model = HardwareModelName();
+  DCHECK(IsStringUTF8(info.manufacturer));
+  DCHECK(IsStringUTF8(info.model));
+  return info;
 }
 
 }  // namespace base
