--- components/viz/host/host_display_client.h.orig	2021-04-14 18:41:02 UTC
+++ components/viz/host/host_display_client.h
@@ -46,7 +46,7 @@ class VIZ_HOST_EXPORT HostDisplayClient : public mojom
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   void DidCompleteSwapWithNewSize(const gfx::Size& size) override;
 #endif
 
