--- ui/compositor/compositor.h.orig	2020-03-16 18:40:43 UTC
+++ ui/compositor/compositor.h
@@ -380,7 +380,7 @@ class COMPOSITOR_EXPORT Compositor : public cc::LayerT
   void OnFirstSurfaceActivation(const viz::SurfaceInfo& surface_info) override;
   void OnFrameTokenChanged(uint32_t frame_token) override;
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   void OnCompleteSwapWithNewSize(const gfx::Size& size);
 #endif
 
