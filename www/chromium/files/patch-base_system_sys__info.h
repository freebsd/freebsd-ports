--- base/system/sys_info.h.orig	2021-09-14 01:51:47 UTC
+++ base/system/sys_info.h
@@ -210,6 +210,8 @@ class BASE_EXPORT SysInfo {
   // On Desktop this returns true when memory <= 512MB.
   static bool IsLowEndDevice();
 
+  static uint64_t MaxSharedMemorySize();
+
  private:
   FRIEND_TEST_ALL_PREFIXES(SysInfoTest, AmountOfAvailablePhysicalMemory);
   FRIEND_TEST_ALL_PREFIXES(debug::SystemMetricsTest, ParseMeminfo);
@@ -219,7 +221,7 @@ class BASE_EXPORT SysInfo {
   static bool IsLowEndDeviceImpl();
   static HardwareInfo GetHardwareInfoSync();
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD) || \
     defined(OS_AIX)
   static int64_t AmountOfAvailablePhysicalMemory(
       const SystemMemoryInfoKB& meminfo);
