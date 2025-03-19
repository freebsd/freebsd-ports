--- components/constrained_window/constrained_window_views.cc.orig	2025-03-18 16:46:04 UTC
+++ components/constrained_window/constrained_window_views.cc
@@ -375,7 +375,7 @@ bool SupportsGlobalScreenCoordinates() {
 }
 
 bool PlatformClipsChildrenToViewport() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
