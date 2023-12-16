--- ui/ozone/platform/wayland/host/wayland_toplevel_window.h.orig	2023-11-22 14:00:11 UTC
+++ ui/ozone/platform/wayland/host/wayland_toplevel_window.h
@@ -256,7 +256,7 @@ class WaylandToplevelWindow : public WaylandWindow,
   // The display ID to switch to in case the state is `kFullscreen`.
   int64_t fullscreen_display_id_ = display::kInvalidDisplayId;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   // Contains the current state of the tiled edges.
   WindowTiledEdges tiled_state_;
 #endif
