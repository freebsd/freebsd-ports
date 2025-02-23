--- ui/ozone/platform/wayland/emulate/wayland_input_emulate.cc.orig	2025-02-22 18:06:53 UTC
+++ ui/ozone/platform/wayland/emulate/wayland_input_emulate.cc
@@ -281,7 +281,7 @@ void WaylandInputEmulate::EmulateUpdateDisplay(const s
 }
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void WaylandInputEmulate::ForceUseScreenCoordinatesOnce() {
   force_use_screen_coordinates_once_ = true;
 }
