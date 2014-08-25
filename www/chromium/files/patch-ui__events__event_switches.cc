--- ./ui/events/event_switches.cc.orig	2014-08-20 21:02:18.000000000 +0200
+++ ./ui/events/event_switches.cc	2014-08-22 15:06:27.000000000 +0200
@@ -32,7 +32,7 @@
 //   disabled: Use the aura gesture detector.
 const char kUnifiedGestureDetectorDisabled[] = "disabled";
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 // Tells chrome to interpret events from these devices as touch events. Only
 // available with XInput 2 (i.e. X server 1.8 or above). The id's of the
 // devices can be retrieved from 'xinput list'.
