--- ui/views/views_switches.cc.orig	2017-06-05 19:03:30 UTC
+++ ui/views/views_switches.cc
@@ -21,7 +21,7 @@ const char kDisableViewsRectBasedTargeting[] =
 const char kDrawViewBoundsRects[] = "draw-view-bounds-rects";
 
 bool IsRectBasedTargetingEnabled() {
-#if defined(OS_CHROMEOS) || defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_CHROMEOS) || defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
   return !base::CommandLine::ForCurrentProcess()->HasSwitch(
       kDisableViewsRectBasedTargeting);
 #else
