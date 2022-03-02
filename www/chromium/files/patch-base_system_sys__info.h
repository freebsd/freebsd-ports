--- base/system/sys_info.h.orig	2022-02-28 16:54:41 UTC
+++ base/system/sys_info.h
@@ -236,6 +236,8 @@ class BASE_EXPORT SysInfo {
   // On Desktop this returns true when memory <= 2GB.
   static bool IsLowEndDevice();
 
+  static uint64_t MaxSharedMemorySize();
+
  private:
   FRIEND_TEST_ALL_PREFIXES(SysInfoTest, AmountOfAvailablePhysicalMemory);
   FRIEND_TEST_ALL_PREFIXES(debug::SystemMetricsTest, ParseMeminfo);
@@ -246,7 +248,7 @@ class BASE_EXPORT SysInfo {
   static HardwareInfo GetHardwareInfoSync();
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_AIX)
+    BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
   static int64_t AmountOfAvailablePhysicalMemory(
       const SystemMemoryInfoKB& meminfo);
 #endif
