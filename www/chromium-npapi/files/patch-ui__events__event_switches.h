--- ./ui/events/event_switches.h.orig	2014-04-30 22:42:57.000000000 +0200
+++ ./ui/events/event_switches.h	2014-05-04 14:38:49.000000000 +0200
@@ -16,7 +16,7 @@
 EVENTS_BASE_EXPORT extern const char kTouchEventsEnabled[];
 EVENTS_BASE_EXPORT extern const char kTouchEventsDisabled[];
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 EVENTS_BASE_EXPORT extern const char kTouchDevices[];
 #endif
 
