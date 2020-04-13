--- chromecast/renderer/cast_content_renderer_client.cc.orig	2020-03-17 09:46:13 UTC
+++ chromecast/renderer/cast_content_renderer_client.cc
@@ -208,7 +208,7 @@ void CastContentRendererClient::RenderFrameCreated(
   dispatcher->OnRenderFrameCreated(render_frame);
 #endif
 
-#if defined(OS_LINUX) && defined(USE_OZONE)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && defined(USE_OZONE)
   // JsChannelBindings destroys itself when the RenderFrame is destroyed.
   JsChannelBindings::Create(render_frame);
 #endif
