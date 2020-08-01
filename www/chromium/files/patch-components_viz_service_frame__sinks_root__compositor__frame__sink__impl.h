--- components/viz/service/frame_sinks/root_compositor_frame_sink_impl.h.orig	2020-07-07 21:57:37 UTC
+++ components/viz/service/frame_sinks/root_compositor_frame_sink_impl.h
@@ -157,7 +157,7 @@ class RootCompositorFrameSinkImpl : public mojom::Comp
   base::TimeDelta preferred_frame_interval_ =
       FrameRateDecider::UnspecifiedFrameInterval();
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   gfx::Size last_swap_pixel_size_;
 #endif
 
