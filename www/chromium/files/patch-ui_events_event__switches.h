--- ui/events/event_switches.h.orig	2018-12-12 22:56:27.000000000 +0100
+++ ui/events/event_switches.h	2019-01-09 23:42:56.991577000 +0100
@@ -13,7 +13,7 @@

 EVENTS_BASE_EXPORT extern const char kCompensateForUnstablePinchZoom[];
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 EVENTS_BASE_EXPORT extern const char kTouchDevices[];
 EVENTS_BASE_EXPORT extern const char kPenDevices[];
 #endif
