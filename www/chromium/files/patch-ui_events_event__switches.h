--- ui/events/event_switches.h.orig	2021-04-14 18:41:39 UTC
+++ ui/events/event_switches.h
@@ -13,7 +13,7 @@ namespace switches {
 
 EVENTS_BASE_EXPORT extern const char kCompensateForUnstablePinchZoom[];
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 EVENTS_BASE_EXPORT extern const char kTouchDevices[];
 EVENTS_BASE_EXPORT extern const char kPenDevices[];
 #endif
