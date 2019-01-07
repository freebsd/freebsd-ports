--- services/device/time_zone_monitor/time_zone_monitor.cc.orig	2018-12-03 21:17:09.000000000 +0100
+++ services/device/time_zone_monitor/time_zone_monitor.cc	2018-12-14 00:48:16.376188000 +0100
@@ -41,7 +41,7 @@
 #else
   std::unique_ptr<icu::TimeZone> new_zone(icu::TimeZone::detectHostTimeZone());
 #endif
-#if defined(OS_LINUX) && !defined(IS_CHROMECAST)
+#if (defined(OS_LINUX) && !defined(IS_CHROMECAST)) || defined(OS_BSD)
   // We get here multiple times on Linux per a single tz change, but
   // want to update the ICU default zone and notify renderer only once.
   std::unique_ptr<icu::TimeZone> current_zone(icu::TimeZone::createDefault());
