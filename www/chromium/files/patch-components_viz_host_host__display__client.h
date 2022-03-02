--- components/viz/host/host_display_client.h.orig	2022-02-28 16:54:41 UTC
+++ components/viz/host/host_display_client.h
@@ -48,7 +48,7 @@ class VIZ_HOST_EXPORT HostDisplayClient : public mojom
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   void DidCompleteSwapWithNewSize(const gfx::Size& size) override;
 #endif
 
