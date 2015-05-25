--- ui/views/views_switches.cc.orig	2015-04-28 07:51:15.723570000 -0400
+++ ui/views/views_switches.cc	2015-04-28 07:51:39.558227000 -0400
@@ -26,7 +26,7 @@
 #endif
 
 bool IsRectBasedTargetingEnabled() {
-#if defined(OS_CHROMEOS) || defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_CHROMEOS) || defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
   return !base::CommandLine::ForCurrentProcess()->HasSwitch(
       kDisableViewsRectBasedTargeting);
 #else
