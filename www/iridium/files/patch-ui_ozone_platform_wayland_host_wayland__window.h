--- ui/ozone/platform/wayland/host/wayland_window.h.orig	2023-08-28 20:17:35 UTC
+++ ui/ozone/platform/wayland/host/wayland_window.h
@@ -236,7 +236,7 @@ class WaylandWindow : public PlatformWindow,
     bool is_snapped_primary = false;
     bool is_snapped_secondary = false;
     bool is_floated = false;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
     WindowTiledEdges tiled_edges;
 #endif
   };
