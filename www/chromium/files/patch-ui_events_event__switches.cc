--- ui/events/event_switches.cc.orig	2017-06-05 19:03:30 UTC
+++ ui/events/event_switches.cc
@@ -17,7 +17,7 @@ const char kEnableScrollPrediction[] = "enable-scroll-
 const char kCompensateForUnstablePinchZoom[] =
     "compensate-for-unstable-pinch-zoom";
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 // Tells chrome to interpret events from these devices as touch events. Only
 // available with XInput 2 (i.e. X server 1.8 or above). The id's of the
 // devices can be retrieved from 'xinput list'.
