--- ui/base/user_activity/user_activity_detector.cc.orig	2015-08-02 12:18:35.398386000 -0400
+++ ui/base/user_activity/user_activity_detector.cc	2015-08-02 12:19:07.874736000 -0400
@@ -52,7 +52,7 @@
 
   ui::PlatformEventSource* platform_event_source =
       ui::PlatformEventSource::GetInstance();
-#if defined(OS_CHROMEOS) || defined(OS_LINUX)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD)
   CHECK(platform_event_source);
 #endif
   if (platform_event_source)
@@ -62,7 +62,7 @@
 UserActivityDetector::~UserActivityDetector() {
   ui::PlatformEventSource* platform_event_source =
       ui::PlatformEventSource::GetInstance();
-#if defined(OS_CHROMEOS) || defined(OS_LINUX)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD)
   CHECK(platform_event_source);
 #endif
   if (platform_event_source)
