--- components/viz/host/host_display_client.h.orig	2021-12-14 11:45:04 UTC
+++ components/viz/host/host_display_client.h
@@ -49,7 +49,7 @@ class VIZ_HOST_EXPORT HostDisplayClient : public mojom
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   void DidCompleteSwapWithNewSize(const gfx::Size& size) override;
 #endif
 
