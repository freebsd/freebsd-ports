--- gpu/command_buffer/service/webgpu_decoder_impl.cc.orig	2022-07-22 17:30:31 UTC
+++ gpu/command_buffer/service/webgpu_decoder_impl.cc
@@ -1064,7 +1064,7 @@ void WebGPUDecoderImpl::RequestAdapterImpl(
 
   if (gr_context_type_ != GrContextType::kVulkan &&
       use_webgpu_adapter_ != WebGPUAdapterName::kCompat) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     callback(WGPURequestAdapterStatus_Unavailable, nullptr,
              "WebGPU on Linux requires command-line flag "
              "--enable-features=Vulkan",
