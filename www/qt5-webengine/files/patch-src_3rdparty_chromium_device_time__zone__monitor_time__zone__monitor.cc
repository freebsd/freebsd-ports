--- src/3rdparty/chromium/device/time_zone_monitor/time_zone_monitor.cc.orig	2017-01-26 00:49:14 UTC
+++ src/3rdparty/chromium/device/time_zone_monitor/time_zone_monitor.cc
@@ -31,7 +31,7 @@ void TimeZoneMonitor::NotifyClients() {
   std::unique_ptr<icu::TimeZone> new_zone(icu::TimeZone::createDefault());
 #else
   icu::TimeZone* new_zone = icu::TimeZone::detectHostTimeZone();
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // We get here multiple times on Linux per a single tz change, but
   // want to update the ICU default zone and notify renderer only once.
   std::unique_ptr<icu::TimeZone> current_zone(icu::TimeZone::createDefault());
