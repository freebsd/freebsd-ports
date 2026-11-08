--- base/system/sys_info.h.orig	2026-08-12 09:02:10 UTC
+++ base/system/sys_info.h
@@ -399,6 +399,8 @@ class BASE_EXPORT SysInfo {
   static void ResetCpuSecurityMitigationsEnabledForTesting();
 #endif
 
+  static uint64_t MaxSharedMemorySize();
+
  private:
   friend class test::ScopedAmountOfPhysicalMemoryOverride;
   FRIEND_TEST_ALL_PREFIXES(SysInfoTest, AmountOfAvailablePhysicalMemory);
@@ -411,7 +413,7 @@ class BASE_EXPORT SysInfo {
   static HardwareInfo GetHardwareInfoSync();
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_AIX)
+    BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
   static ByteSize AmountOfAvailablePhysicalMemory(
       const SystemMemoryInfo& meminfo);
 #endif
