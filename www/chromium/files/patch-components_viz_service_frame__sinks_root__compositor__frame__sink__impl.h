--- components/viz/service/frame_sinks/root_compositor_frame_sink_impl.h.orig	2020-05-13 18:40:30 UTC
+++ components/viz/service/frame_sinks/root_compositor_frame_sink_impl.h
@@ -151,7 +151,7 @@ class RootCompositorFrameSinkImpl : public mojom::Comp
   base::TimeDelta preferred_frame_interval_ =
       FrameRateDecider::UnspecifiedFrameInterval();
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   gfx::Size last_swap_pixel_size_;
 #endif
 
