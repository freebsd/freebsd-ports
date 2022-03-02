--- content/renderer/renderer_blink_platform_impl.h.orig	2022-02-28 16:54:41 UTC
+++ content/renderer/renderer_blink_platform_impl.h
@@ -29,7 +29,7 @@
 #include "third_party/blink/public/mojom/cache_storage/cache_storage.mojom.h"
 #include "third_party/blink/public/mojom/loader/code_cache.mojom.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/services/font/public/cpp/font_loader.h"  // nogncheck
 #include "third_party/skia/include/core/SkRefCnt.h"           // nogncheck
 #endif
@@ -274,7 +274,7 @@ class CONTENT_EXPORT RendererBlinkPlatformImpl : publi
   void Collect3DContextInformation(blink::Platform::GraphicsInfo* gl_info,
                                    const gpu::GPUInfo& gpu_info) const;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   std::unique_ptr<blink::WebSandboxSupport> sandbox_support_;
 #endif
 
@@ -298,7 +298,7 @@ class CONTENT_EXPORT RendererBlinkPlatformImpl : publi
   mojo::SharedRemote<blink::mojom::CodeCacheHost> code_cache_host_
       GUARDED_BY(code_cache_host_lock_);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   sk_sp<font_service::FontLoader> font_loader_;
 #endif
 
