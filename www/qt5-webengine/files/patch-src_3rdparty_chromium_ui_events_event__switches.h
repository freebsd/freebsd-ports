--- src/3rdparty/chromium/ui/events/event_switches.h.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/ui/events/event_switches.h
@@ -13,7 +13,7 @@ EVENTS_BASE_EXPORT extern const char kCompensateForUns
 
 EVENTS_BASE_EXPORT extern const char kCompensateForUnstablePinchZoom[];
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 EVENTS_BASE_EXPORT extern const char kTouchDevices[];
 EVENTS_BASE_EXPORT extern const char kPenDevices[];
 #endif
