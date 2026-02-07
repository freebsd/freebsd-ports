--- src/3rdparty/chromium/components/constrained_window/constrained_window_views.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/components/constrained_window/constrained_window_views.cc
@@ -375,7 +375,7 @@ bool PlatformClipsChildrenToViewport() {
 }
 
 bool PlatformClipsChildrenToViewport() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
