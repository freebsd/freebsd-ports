--- src/3rdparty/chromium/ui/events/event_switches.h.orig	2017-01-26 00:49:31 UTC
+++ src/3rdparty/chromium/ui/events/event_switches.h
@@ -18,7 +18,7 @@ EVENTS_BASE_EXPORT extern const char kTo
 EVENTS_BASE_EXPORT extern const char kTouchEventsDisabled[];
 EVENTS_BASE_EXPORT extern const char kCompensateForUnstablePinchZoom[];
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 EVENTS_BASE_EXPORT extern const char kTouchDevices[];
 #endif
 
