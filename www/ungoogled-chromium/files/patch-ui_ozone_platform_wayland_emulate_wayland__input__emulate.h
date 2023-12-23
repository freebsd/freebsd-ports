--- ui/ozone/platform/wayland/emulate/wayland_input_emulate.h.orig	2023-12-23 12:33:28 UTC
+++ ui/ozone/platform/wayland/emulate/wayland_input_emulate.h
@@ -61,7 +61,7 @@ class WaylandInputEmulate : public wl::WaylandProxy::D
                     int touch_id,
                     uint32_t request_id);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void ForceUseScreenCoordinatesOnce();
 #endif
 
