--- src/3rdparty/chromium/content/renderer/renderer_blink_platform_impl.h.orig	2023-08-16 19:50:41 UTC
+++ src/3rdparty/chromium/content/renderer/renderer_blink_platform_impl.h
@@ -32,7 +32,7 @@
 #include "third_party/blink/public/common/user_agent/user_agent_metadata.h"
 #include "third_party/blink/public/mojom/cache_storage/cache_storage.mojom.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/services/font/public/cpp/font_loader.h"  // nogncheck
 #include "third_party/skia/include/core/SkRefCnt.h"           // nogncheck
 #endif
@@ -245,7 +245,7 @@ class CONTENT_EXPORT RendererBlinkPlatformImpl : publi
   void Collect3DContextInformation(blink::Platform::GraphicsInfo* gl_info,
                                    const gpu::GPUInfo& gpu_info) const;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   std::unique_ptr<blink::WebSandboxSupport> sandbox_support_;
 #endif
 
@@ -265,7 +265,7 @@ class CONTENT_EXPORT RendererBlinkPlatformImpl : publi
   mutable base::WaitableEvent io_thread_id_ready_event_;
   base::PlatformThreadId io_thread_id_ = base::kInvalidThreadId;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   sk_sp<font_service::FontLoader> font_loader_;
 #endif
 
