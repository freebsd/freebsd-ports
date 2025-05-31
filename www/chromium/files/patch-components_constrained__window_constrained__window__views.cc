--- components/constrained_window/constrained_window_views.cc.orig	2025-05-28 14:55:43 UTC
+++ components/constrained_window/constrained_window_views.cc
@@ -385,7 +385,7 @@ bool SupportsGlobalScreenCoordinates() {
 }
 
 bool PlatformClipsChildrenToViewport() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
