--- content/renderer/renderer_blink_platform_impl.h.orig	2024-04-12 16:47:26 UTC
+++ content/renderer/renderer_blink_platform_impl.h
@@ -237,7 +237,7 @@ class CONTENT_EXPORT RendererBlinkPlatformImpl : publi
 #endif  // BUILDFLAG(IS_ANDROID)
 
   // Tells this platform that the renderer is locked to a site (i.e., a scheme
-  // plus eTLD+1, such as https://9oo91e.qjz9zk), or to a more specific origin.
+  // plus eTLD+1, such as https://google.com), or to a more specific origin.
   void SetIsLockedToSite();
 
  private:
@@ -246,7 +246,7 @@ class CONTENT_EXPORT RendererBlinkPlatformImpl : publi
   void Collect3DContextInformation(blink::Platform::GraphicsInfo* gl_info,
                                    const gpu::GPUInfo& gpu_info) const;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   std::unique_ptr<blink::WebSandboxSupport> sandbox_support_;
 #endif
 
