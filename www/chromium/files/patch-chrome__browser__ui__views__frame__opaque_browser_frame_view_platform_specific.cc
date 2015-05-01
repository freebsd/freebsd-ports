--- ./chrome/browser/ui/views/frame/opaque_browser_frame_view_platform_specific.cc.orig	2015-04-30 16:57:02.000000000 +0200
+++ ./chrome/browser/ui/views/frame/opaque_browser_frame_view_platform_specific.cc	2015-04-30 16:56:00.000000000 +0200
@@ -10,7 +10,7 @@
   return false;
 }
 
-#if !defined(OS_LINUX)
+#if !defined(OS_LINUX) && !defined(OS_FREEBSD)
 
 // static
 OpaqueBrowserFrameViewPlatformSpecific*
