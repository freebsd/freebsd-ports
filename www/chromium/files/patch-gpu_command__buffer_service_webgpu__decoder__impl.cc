--- gpu/command_buffer/service/webgpu_decoder_impl.cc.orig	2022-02-07 13:39:41 UTC
+++ gpu/command_buffer/service/webgpu_decoder_impl.cc
@@ -1021,7 +1021,7 @@ error::Error WebGPUDecoderImpl::HandleRequestAdapter(
   }
 
   if (gr_context_type_ != GrContextType::kVulkan) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     SendAdapterProperties(request_adapter_serial, -1, nullptr,
                           "WebGPU on Linux requires command-line flag "
                           "--enable-features=Vulkan,UseSkiaRenderer");
