--- content/renderer/renderer_blink_platform_impl.h.orig	2025-09-11 13:19:19 UTC
+++ content/renderer/renderer_blink_platform_impl.h
@@ -273,7 +273,7 @@ class CONTENT_EXPORT RendererBlinkPlatformImpl : publi
                                    const gpu::GPUInfo& gpu_info) const;
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   std::unique_ptr<blink::WebSandboxSupport> sandbox_support_;
 #endif
 
