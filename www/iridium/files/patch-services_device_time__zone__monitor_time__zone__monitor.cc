--- services/device/time_zone_monitor/time_zone_monitor.cc.orig	2017-09-05 21:05:23.000000000 +0200
+++ services/device/time_zone_monitor/time_zone_monitor.cc	2017-09-06 21:23:20.120961000 +0200
@@ -41,7 +41,7 @@
 #else
   std::unique_ptr<icu::TimeZone> new_zone(icu::TimeZone::detectHostTimeZone());
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // We get here multiple times on Linux per a single tz change, but
   // want to update the ICU default zone and notify renderer only once.
   std::unique_ptr<icu::TimeZone> current_zone(icu::TimeZone::createDefault());
