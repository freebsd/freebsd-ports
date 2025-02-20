--- components/constrained_window/constrained_window_views.cc.orig	2025-02-19 07:43:18 UTC
+++ components/constrained_window/constrained_window_views.cc
@@ -371,7 +371,7 @@ bool SupportsGlobalScreenCoordinates() {
 }
 
 bool PlatformClipsChildrenToViewport() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
