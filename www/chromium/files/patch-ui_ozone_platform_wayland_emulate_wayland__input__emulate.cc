--- ui/ozone/platform/wayland/emulate/wayland_input_emulate.cc.orig	2023-12-10 06:10:27 UTC
+++ ui/ozone/platform/wayland/emulate/wayland_input_emulate.cc
@@ -230,7 +230,7 @@ void WaylandInputEmulate::EmulateTouch(int action,
   wayland_proxy->FlushForTesting();
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void WaylandInputEmulate::ForceUseScreenCoordinatesOnce() {
   force_use_screen_coordinates_once_ = true;
 }
