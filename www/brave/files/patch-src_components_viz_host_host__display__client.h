--- src/components/viz/host/host_display_client.h.orig	2026-10-18 18:43:23 UTC
+++ src/components/viz/host/host_display_client.h
@@ -52,7 +52,7 @@ class VIZ_HOST_EXPORT HostDisplayClient
   void AddChildWindowToBrowser(gpu::SurfaceHandle child_window) override;
 #endif
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(SUPPORTS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(SUPPORTS_OZONE_X11)
   void DidCompleteSwapWithNewSize(const gfx::Size& size) override;
 #endif  // BUILDFLAG(IS_LINUX) && BUILDFLAG(SUPPORTS_OZONE_X11)
 
