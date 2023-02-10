--- components/viz/service/frame_sinks/root_compositor_frame_sink_impl.h.orig	2023-01-17 19:19:00 UTC
+++ components/viz/service/frame_sinks/root_compositor_frame_sink_impl.h
@@ -197,7 +197,7 @@ class VIZ_SERVICE_EXPORT RootCompositorFrameSinkImpl
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   gfx::Size last_swap_pixel_size_;
 #endif
 
