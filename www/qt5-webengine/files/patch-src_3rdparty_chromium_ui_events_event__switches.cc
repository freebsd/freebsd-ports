--- src/3rdparty/chromium/ui/events/event_switches.cc.orig	2017-01-26 00:49:31 UTC
+++ src/3rdparty/chromium/ui/events/event_switches.cc
@@ -28,7 +28,7 @@ const char kTouchEventsDisabled[] = "dis
 const char kCompensateForUnstablePinchZoom[] =
     "compensate-for-unstable-pinch-zoom";
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 // Tells chrome to interpret events from these devices as touch events. Only
 // available with XInput 2 (i.e. X server 1.8 or above). The id's of the
 // devices can be retrieved from 'xinput list'.
