--- components/viz/service/frame_sinks/root_compositor_frame_sink_impl.h.orig	2025-10-21 16:57:35 UTC
+++ components/viz/service/frame_sinks/root_compositor_frame_sink_impl.h
@@ -222,7 +222,7 @@ class VIZ_SERVICE_EXPORT RootCompositorFrameSinkImpl
   base::TimeDelta display_frame_interval_ = BeginFrameArgs::DefaultInterval();
   base::TimeDelta preferred_frame_interval_;
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(IS_OZONE_X11)
   gfx::Size last_swap_pixel_size_;
 #endif  // BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
 
