--- content/public/test/mock_render_process_host.h.orig	2023-04-28 17:01:32 UTC
+++ content/public/test/mock_render_process_host.h
@@ -278,7 +278,7 @@ class MockRenderProcessHost : public RenderProcessHost
       const blink::StorageKey& storage_key,
       mojo::PendingReceiver<blink::mojom::WebSocketConnector> receiver)
       override {}
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   void CreateStableVideoDecoder(
       mojo::PendingReceiver<media::stable::mojom::StableVideoDecoder> receiver)
       override {}
