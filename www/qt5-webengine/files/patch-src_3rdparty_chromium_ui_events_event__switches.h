--- src/3rdparty/chromium/ui/events/event_switches.h.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/ui/events/event_switches.h
@@ -14,7 +14,7 @@ namespace switches {
 EVENTS_BASE_EXPORT extern const char kEnableScrollPrediction[];
 EVENTS_BASE_EXPORT extern const char kCompensateForUnstablePinchZoom[];
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 EVENTS_BASE_EXPORT extern const char kTouchDevices[];
 EVENTS_BASE_EXPORT extern const char kPenDevices[];
 #endif
