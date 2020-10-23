--- chromecast/renderer/cast_content_renderer_client.cc.orig	2020-09-08 19:14:03 UTC
+++ chromecast/renderer/cast_content_renderer_client.cc
@@ -207,7 +207,7 @@ void CastContentRendererClient::RenderFrameCreated(
   dispatcher->OnRenderFrameCreated(render_frame);
 #endif
 
-#if defined(OS_LINUX) && defined(USE_OZONE)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && defined(USE_OZONE)
   // JsChannelBindings destroys itself when the RenderFrame is destroyed.
   JsChannelBindings::Create(render_frame);
 #endif
