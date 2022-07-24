--- chromecast/renderer/cast_content_renderer_client.cc.orig	2022-07-22 17:30:31 UTC
+++ chromecast/renderer/cast_content_renderer_client.cc
@@ -191,7 +191,7 @@ void CastContentRendererClient::RenderFrameCreated(
   dispatcher->OnRenderFrameCreated(render_frame);
 #endif
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && defined(USE_OZONE)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && defined(USE_OZONE)
   // JsChannelBindings destroys itself when the RenderFrame is destroyed.
   JsChannelBindings::Create(render_frame);
 #endif
