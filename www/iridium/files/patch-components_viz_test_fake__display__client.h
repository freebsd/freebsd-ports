--- components/viz/test/fake_display_client.h.orig	2023-01-17 19:19:00 UTC
+++ components/viz/test/fake_display_client.h
@@ -35,7 +35,7 @@ class FakeDisplayClient : public mojom::DisplayClient 
   void AddChildWindowToBrowser(gpu::SurfaceHandle child_window) override;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void DidCompleteSwapWithNewSize(const gfx::Size& size) override;
 #endif
 
