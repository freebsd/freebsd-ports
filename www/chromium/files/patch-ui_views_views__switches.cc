--- ui/views/views_switches.cc.orig	2016-03-25 13:05:04 UTC
+++ ui/views/views_switches.cc
@@ -18,7 +18,7 @@ const char kDisableViewsRectBasedTargeti
     "disable-views-rect-based-targeting";
 
 bool IsRectBasedTargetingEnabled() {
-#if defined(OS_CHROMEOS) || defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_CHROMEOS) || defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
   return !base::CommandLine::ForCurrentProcess()->HasSwitch(
       kDisableViewsRectBasedTargeting);
 #else
