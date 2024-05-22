--- content/browser/devtools/devtools_frontend_host_impl.h.orig	2024-05-21 18:07:39 UTC
+++ content/browser/devtools/devtools_frontend_host_impl.h
@@ -34,7 +34,7 @@ class DevToolsFrontendHostImpl : public DevToolsFronte
 
   void BadMessageReceived() override;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   void OnDidAddMessageToConsole(
       RenderFrameHost* source_frame,
       blink::mojom::ConsoleMessageLevel log_level,
