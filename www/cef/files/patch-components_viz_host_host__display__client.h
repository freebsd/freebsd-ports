--- components/viz/host/host_display_client.h.orig	2026-03-13 06:02:14 UTC
+++ components/viz/host/host_display_client.h
@@ -52,7 +52,7 @@ class VIZ_HOST_EXPORT HostDisplayClient : public mojom
   void AddChildWindowToBrowser(gpu::SurfaceHandle child_window) override;
 #endif
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(SUPPORTS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(SUPPORTS_OZONE_X11)
   void DidCompleteSwapWithNewSize(const gfx::Size& size) override;
 #endif  // BUILDFLAG(IS_LINUX) && BUILDFLAG(SUPPORTS_OZONE_X11)
 
