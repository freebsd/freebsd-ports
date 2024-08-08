--- components/constrained_window/constrained_window_views.cc.orig	2024-08-01 05:47:53 UTC
+++ components/constrained_window/constrained_window_views.cc
@@ -360,7 +360,7 @@ bool SupportsGlobalScreenCoordinates() {
 }
 
 bool PlatformClipsChildrenToViewport() {
-#if BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
