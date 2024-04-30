--- src/3rdparty/chromium/content/renderer/renderer_blink_platform_impl.h.orig	2023-12-12 22:08:45 UTC
+++ src/3rdparty/chromium/content/renderer/renderer_blink_platform_impl.h
@@ -238,7 +238,7 @@ class CONTENT_EXPORT RendererBlinkPlatformImpl : publi
   void Collect3DContextInformation(blink::Platform::GraphicsInfo* gl_info,
                                    const gpu::GPUInfo& gpu_info) const;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   std::unique_ptr<blink::WebSandboxSupport> sandbox_support_;
 #endif
 
