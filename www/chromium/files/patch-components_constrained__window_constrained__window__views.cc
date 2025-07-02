--- components/constrained_window/constrained_window_views.cc.orig	2025-07-02 06:08:04 UTC
+++ components/constrained_window/constrained_window_views.cc
@@ -392,7 +392,7 @@ bool SupportsGlobalScreenCoordinates() {
 }
 
 bool PlatformClipsChildrenToViewport() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
