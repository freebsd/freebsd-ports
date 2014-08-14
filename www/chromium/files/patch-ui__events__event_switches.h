--- ./ui/events/event_switches.h.orig	2014-08-12 21:02:29.000000000 +0200
+++ ./ui/events/event_switches.h	2014-08-13 09:57:00.000000000 +0200
@@ -17,7 +17,7 @@
 EVENTS_BASE_EXPORT extern const char kTouchEventsDisabled[];
 EVENTS_BASE_EXPORT extern const char kUseUnifiedGestureDetector[];
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 EVENTS_BASE_EXPORT extern const char kTouchDevices[];
 #endif
 
