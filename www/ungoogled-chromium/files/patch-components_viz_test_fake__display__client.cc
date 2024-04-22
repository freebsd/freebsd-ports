--- components/viz/test/fake_display_client.cc.orig	2024-02-03 15:42:55 UTC
+++ components/viz/test/fake_display_client.cc
@@ -27,7 +27,7 @@ void FakeDisplayClient::AddChildWindowToBrowser(
     gpu::SurfaceHandle child_window) {}
 #endif
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(IS_OZONE_X11)
 void FakeDisplayClient::DidCompleteSwapWithNewSize(const gfx::Size& size) {}
 #endif  // BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
 
