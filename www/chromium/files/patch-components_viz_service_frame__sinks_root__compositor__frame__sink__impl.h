--- components/viz/service/frame_sinks/root_compositor_frame_sink_impl.h.orig	2026-03-13 06:02:14 UTC
+++ components/viz/service/frame_sinks/root_compositor_frame_sink_impl.h
@@ -220,7 +220,7 @@ class VIZ_SERVICE_EXPORT RootCompositorFrameSinkImpl
   base::TimeDelta display_frame_interval_ = BeginFrameArgs::DefaultInterval();
   base::TimeDelta preferred_frame_interval_;
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(SUPPORTS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(SUPPORTS_OZONE_X11)
   gfx::Size last_swap_pixel_size_;
 #endif  // BUILDFLAG(IS_LINUX) && BUILDFLAG(SUPPORTS_OZONE_X11)
 
