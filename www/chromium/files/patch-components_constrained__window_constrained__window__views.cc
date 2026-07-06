--- components/constrained_window/constrained_window_views.cc.orig	2026-07-01 06:24:19 UTC
+++ components/constrained_window/constrained_window_views.cc
@@ -413,7 +413,7 @@ bool SupportsGlobalScreenCoordinates() {
 }
 
 bool PlatformClipsChildrenToViewport() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
