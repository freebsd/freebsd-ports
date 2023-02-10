--- components/viz/test/fake_display_client.cc.orig	2023-01-17 19:19:00 UTC
+++ components/viz/test/fake_display_client.cc
@@ -27,7 +27,7 @@ void FakeDisplayClient::AddChildWindowToBrowser(
     gpu::SurfaceHandle child_window) {}
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void FakeDisplayClient::DidCompleteSwapWithNewSize(const gfx::Size& size) {}
 #endif
 
