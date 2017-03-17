--- ui/events/event_switches.h.orig	2017-03-09 20:04:49 UTC
+++ ui/events/event_switches.h
@@ -14,7 +14,7 @@ namespace switches {
 EVENTS_BASE_EXPORT extern const char kEnableScrollPrediction[];
 EVENTS_BASE_EXPORT extern const char kCompensateForUnstablePinchZoom[];
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 EVENTS_BASE_EXPORT extern const char kTouchDevices[];
 #endif
 
