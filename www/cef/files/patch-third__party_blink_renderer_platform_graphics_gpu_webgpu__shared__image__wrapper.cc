--- third_party/blink/renderer/platform/graphics/gpu/webgpu_shared_image_wrapper.cc.orig	2026-08-31 10:59:09 UTC
+++ third_party/blink/renderer/platform/graphics/gpu/webgpu_shared_image_wrapper.cc
@@ -108,7 +108,7 @@ std::unique_ptr<WebGpuSharedImageWrapper> WebGpuShared
     return nullptr;
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // WebGpu preferred canvas on linux is RGBA and interop (vk on gl) is
   // dependent on canvas copies being RGBA (not BGRA).
   if (format != viz::SinglePlaneFormat::kRGBA_F16) {
