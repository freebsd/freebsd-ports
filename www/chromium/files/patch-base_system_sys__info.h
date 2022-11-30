--- base/system/sys_info.h.orig	2022-11-30 08:12:58 UTC
+++ base/system/sys_info.h
@@ -233,6 +233,8 @@ class BASE_EXPORT SysInfo {
   static void SetIsCpuSecurityMitigationsEnabled(bool is_enabled);
 #endif
 
+  static uint64_t MaxSharedMemorySize();
+
  private:
   FRIEND_TEST_ALL_PREFIXES(SysInfoTest, AmountOfAvailablePhysicalMemory);
   FRIEND_TEST_ALL_PREFIXES(debug::SystemMetricsTest, ParseMeminfo);
@@ -243,7 +245,7 @@ class BASE_EXPORT SysInfo {
   static HardwareInfo GetHardwareInfoSync();
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_AIX)
+    BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
   static uint64_t AmountOfAvailablePhysicalMemory(
       const SystemMemoryInfoKB& meminfo);
 #endif
