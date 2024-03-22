--- components/constrained_window/constrained_window_views.cc.orig	2024-03-22 08:19:40 UTC
+++ components/constrained_window/constrained_window_views.cc
@@ -324,7 +324,7 @@ bool SupportsGlobalScreenCoordinates() {
 }
 
 bool PlatformClipsChildrenToViewport() {
-#if BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
