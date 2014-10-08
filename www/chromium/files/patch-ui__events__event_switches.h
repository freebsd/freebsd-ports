--- ui/events/event_switches.h.orig	2014-10-02 17:39:48 UTC
+++ ui/events/event_switches.h
@@ -21,7 +21,7 @@
 EVENTS_BASE_EXPORT extern const char kUnifiedGestureDetectorDisabled[];
 EVENTS_BASE_EXPORT extern const char kCompensateForUnstablePinchZoom[];
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 EVENTS_BASE_EXPORT extern const char kTouchDevices[];
 #endif
 
