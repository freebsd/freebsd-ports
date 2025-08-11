--- components/viz/service/frame_sinks/root_compositor_frame_sink_impl.h.orig	2025-08-07 06:57:29 UTC
+++ components/viz/service/frame_sinks/root_compositor_frame_sink_impl.h
@@ -229,7 +229,7 @@ class VIZ_SERVICE_EXPORT RootCompositorFrameSinkImpl
   base::TimeDelta display_frame_interval_ = BeginFrameArgs::DefaultInterval();
   base::TimeDelta preferred_frame_interval_;
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(IS_OZONE_X11)
   gfx::Size last_swap_pixel_size_;
 #endif  // BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
 
