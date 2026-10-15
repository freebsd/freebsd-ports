--- cef/libcef/browser/osr/host_display_client_osr.h.orig	2026-09-06 17:31:54 UTC
+++ cef/libcef/browser/osr/host_display_client_osr.h
@@ -37,7 +37,7 @@ class CefHostDisplayClientOSR : public v
       mojo::PendingReceiver<viz::mojom::LayeredWindowUpdater> receiver)
       override;
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(SUPPORTS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(SUPPORTS_OZONE_X11)
   void DidCompleteSwapWithNewSize(const gfx::Size& size) override;
 #endif
 
