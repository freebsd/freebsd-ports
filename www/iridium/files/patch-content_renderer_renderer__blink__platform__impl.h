--- content/renderer/renderer_blink_platform_impl.h.orig	2026-11-17 21:17:00 UTC
+++ content/renderer/renderer_blink_platform_impl.h
@@ -288,7 +288,7 @@ class CONTENT_EXPORT RendererBlinkPlatformImpl : publi
                                const gpu::GPUInfo& gpu_info) const;
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   std::unique_ptr<blink::WebSandboxSupport> sandbox_support_;
 #endif
 
