--- content/browser/devtools/devtools_frontend_host_impl.h.orig	2025-10-21 16:57:35 UTC
+++ content/browser/devtools/devtools_frontend_host_impl.h
@@ -33,7 +33,7 @@ class DevToolsFrontendHostImpl : public DevToolsFronte
 
   void BadMessageReceived() override;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   void OnDidAddMessageToConsole(
       RenderFrameHost* source_frame,
       blink::mojom::ConsoleMessageLevel log_level,
