--- components/viz/service/frame_sinks/root_compositor_frame_sink_impl.h.orig	2024-01-30 07:53:34 UTC
+++ components/viz/service/frame_sinks/root_compositor_frame_sink_impl.h
@@ -210,7 +210,7 @@ class VIZ_SERVICE_EXPORT RootCompositorFrameSinkImpl
   // to actually unref.
   LocalSurfaceId to_evict_on_next_draw_and_swap_ = LocalSurfaceId();
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(IS_OZONE_X11)
   gfx::Size last_swap_pixel_size_;
 #endif  // BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
 
