--- components/viz/service/frame_sinks/root_compositor_frame_sink_impl.h.orig	2024-08-26 14:40:28 UTC
+++ components/viz/service/frame_sinks/root_compositor_frame_sink_impl.h
@@ -214,7 +214,7 @@ class VIZ_SERVICE_EXPORT RootCompositorFrameSinkImpl
   // See comments on `EvictionHandler`.
   EvictionHandler eviction_handler_;
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(IS_OZONE_X11)
   gfx::Size last_swap_pixel_size_;
 #endif  // BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
 
