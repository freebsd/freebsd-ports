--- services/device/time_zone_monitor/time_zone_monitor_linux.cc.orig	2025-03-05 08:14:56 UTC
+++ services/device/time_zone_monitor/time_zone_monitor_linux.cc
@@ -131,9 +131,12 @@ class TimeZoneMonitorLinuxImpl
     // false positives are harmless, assuming the false positive rate is
     // reasonable.
     const auto kFilesToWatch = std::to_array<const char*>({
+#if BUILDFLAG(IS_BSD)
         "/etc/localtime",
+#else
         "/etc/timezone",
         "/etc/TZ",
+#endif
     });
     for (size_t index = 0; index < std::size(kFilesToWatch); ++index) {
       file_path_watchers_.push_back(std::make_unique<base::FilePathWatcher>());
