--- ui/ozone/platform/wayland/emulate/wayland_input_emulate.cc.orig	2024-03-22 08:19:40 UTC
+++ ui/ozone/platform/wayland/emulate/wayland_input_emulate.cc
@@ -284,7 +284,7 @@ void WaylandInputEmulate::EmulateUpdateDisplay(const s
 }
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void WaylandInputEmulate::ForceUseScreenCoordinatesOnce() {
   force_use_screen_coordinates_once_ = true;
 }
