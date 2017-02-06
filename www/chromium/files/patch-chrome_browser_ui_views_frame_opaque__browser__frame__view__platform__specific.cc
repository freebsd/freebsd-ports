--- chrome/browser/ui/views/frame/opaque_browser_frame_view_platform_specific.cc.orig	2017-01-26 00:49:09 UTC
+++ chrome/browser/ui/views/frame/opaque_browser_frame_view_platform_specific.cc
@@ -10,7 +10,7 @@ bool OpaqueBrowserFrameViewPlatformSpeci
   return false;
 }
 
-#if !defined(OS_LINUX)
+#if !defined(OS_LINUX) && !defined(OS_FREEBSD)
 
 // static
 OpaqueBrowserFrameViewPlatformSpecific*
