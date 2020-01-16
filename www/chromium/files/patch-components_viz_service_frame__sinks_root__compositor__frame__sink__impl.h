--- components/viz/service/frame_sinks/root_compositor_frame_sink_impl.h.orig	2019-12-17 19:31:54 UTC
+++ components/viz/service/frame_sinks/root_compositor_frame_sink_impl.h
@@ -140,7 +140,7 @@ class RootCompositorFrameSinkImpl : public mojom::Comp
   // to the BFS.
   std::unique_ptr<Display> display_;
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   gfx::Size last_swap_pixel_size_;
 #endif
 
