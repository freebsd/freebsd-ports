--- components/sync/service/device_statistics_tracker.cc.orig	2026-06-05 13:45:06 UTC
+++ components/sync/service/device_statistics_tracker.cc
@@ -139,7 +139,7 @@ std::optional<DeviceStatisticsTracker::Platform> GetLo
   return DeviceStatisticsTracker::Platform::kWindows;
 #elif BUILDFLAG(IS_MAC)
   return DeviceStatisticsTracker::Platform::kMac;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return DeviceStatisticsTracker::Platform::kLinux;
 #elif BUILDFLAG(IS_CHROMEOS)
   return DeviceStatisticsTracker::Platform::kChromeOS;
