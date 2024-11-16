--- content/renderer/renderer_blink_platform_impl.h.orig	2024-11-14 07:57:23 UTC
+++ content/renderer/renderer_blink_platform_impl.h
@@ -254,7 +254,7 @@ class CONTENT_EXPORT RendererBlinkPlatformImpl : publi
   void Collect3DContextInformation(blink::Platform::GraphicsInfo* gl_info,
                                    const gpu::GPUInfo& gpu_info) const;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   std::unique_ptr<blink::WebSandboxSupport> sandbox_support_;
 #endif
 
