--- src/3rdparty/chromium/base/system/sys_info.h.orig	2023-02-08 09:03:45 UTC
+++ src/3rdparty/chromium/base/system/sys_info.h
@@ -246,6 +246,8 @@ class BASE_EXPORT SysInfo {
   static void SetIsCpuSecurityMitigationsEnabled(bool is_enabled);
 #endif
 
+  static uint64_t MaxSharedMemorySize();
+
  private:
   FRIEND_TEST_ALL_PREFIXES(SysInfoTest, AmountOfAvailablePhysicalMemory);
   FRIEND_TEST_ALL_PREFIXES(debug::SystemMetricsTest, ParseMeminfo);
@@ -257,7 +259,7 @@ class BASE_EXPORT SysInfo {
   static HardwareInfo GetHardwareInfoSync();
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_AIX)
+    BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
   static uint64_t AmountOfAvailablePhysicalMemory(
       const SystemMemoryInfoKB& meminfo);
 #endif
