--- components/constrained_window/constrained_window_views.cc.orig	2026-08-12 09:02:10 UTC
+++ components/constrained_window/constrained_window_views.cc
@@ -419,7 +419,7 @@ bool SupportsGlobalScreenCoordinates() {
 }
 
 bool PlatformClipsChildrenToViewport() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
