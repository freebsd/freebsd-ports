--- content/browser/time_zone_monitor.cc.orig	2015-08-02 12:15:31.521732000 -0400
+++ content/browser/time_zone_monitor.cc	2015-08-02 12:16:05.094405000 -0400
@@ -28,7 +28,7 @@
   scoped_ptr<icu::TimeZone> new_zone(icu::TimeZone::createDefault());
 #else
   icu::TimeZone* new_zone = icu::TimeZone::detectHostTimeZone();
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // We get here multiple times on Linux per a single tz change, but
   // want to update the ICU default zone and notify renderer only once.
   scoped_ptr<icu::TimeZone> current_zone(icu::TimeZone::createDefault());
