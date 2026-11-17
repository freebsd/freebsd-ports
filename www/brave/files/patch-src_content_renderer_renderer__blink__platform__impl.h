--- src/content/renderer/renderer_blink_platform_impl.h.orig	2026-10-18 18:43:23 UTC
+++ src/content/renderer/renderer_blink_platform_impl.h
@@ -287,7 +287,7 @@ class CONTENT_EXPORT RendererBlinkPlatfo
                                const gpu::GPUInfo& gpu_info) const;
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   std::unique_ptr<blink::WebSandboxSupport> sandbox_support_;
 #endif
 
