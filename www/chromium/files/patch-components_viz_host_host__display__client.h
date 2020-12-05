--- components/viz/host/host_display_client.h.orig	2020-11-13 06:36:42 UTC
+++ components/viz/host/host_display_client.h
@@ -43,7 +43,7 @@ class VIZ_HOST_EXPORT HostDisplayClient : public mojom
       mojo::PendingReceiver<mojom::LayeredWindowUpdater> receiver) override;
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   void DidCompleteSwapWithNewSize(const gfx::Size& size) override;
 #endif
 
