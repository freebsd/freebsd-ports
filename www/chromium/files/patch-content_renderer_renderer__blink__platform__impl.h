--- content/renderer/renderer_blink_platform_impl.h.orig	2023-01-11 09:17:16 UTC
+++ content/renderer/renderer_blink_platform_impl.h
@@ -30,7 +30,7 @@
 #include "third_party/blink/public/common/user_agent/user_agent_metadata.h"
 #include "third_party/blink/public/mojom/cache_storage/cache_storage.mojom.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/services/font/public/cpp/font_loader.h"  // nogncheck
 #include "third_party/skia/include/core/SkRefCnt.h"           // nogncheck
 #endif
@@ -172,7 +172,7 @@ class CONTENT_EXPORT RendererBlinkPlatformImpl : publi
       const blink::WebURL& top_document_web_url) override;
   gpu::GpuMemoryBufferManager* GetGpuMemoryBufferManager() override;
   blink::WebString ConvertIDNToUnicode(const blink::WebString& host) override;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   void SetThreadType(base::PlatformThreadId thread_id,
                      base::ThreadType) override;
 #endif
@@ -240,7 +240,7 @@ class CONTENT_EXPORT RendererBlinkPlatformImpl : publi
   void Collect3DContextInformation(blink::Platform::GraphicsInfo* gl_info,
                                    const gpu::GPUInfo& gpu_info) const;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   std::unique_ptr<blink::WebSandboxSupport> sandbox_support_;
 #endif
 
@@ -260,7 +260,7 @@ class CONTENT_EXPORT RendererBlinkPlatformImpl : publi
   mutable base::WaitableEvent io_thread_id_ready_event_;
   base::PlatformThreadId io_thread_id_ = base::kInvalidThreadId;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   sk_sp<font_service::FontLoader> font_loader_;
 #endif
 
