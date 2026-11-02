--- src/3rdparty/chromium/gpu/command_buffer/service/webgpu_decoder_impl.cc.orig	2026-10-21 00:29:58 UTC
+++ src/3rdparty/chromium/gpu/command_buffer/service/webgpu_decoder_impl.cc
@@ -1745,7 +1745,7 @@ wgpu::Adapter WebGPUDecoderImpl::CreatePreferredAdapte
       backend_types = {wgpu::BackendType::D3D12};
 #elif BUILDFLAG(IS_APPLE)
       backend_types = {wgpu::BackendType::Metal};
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       if (shared_context_state_->GrContextIsVulkan() ||
           shared_context_state_->IsGraphiteDawnVulkan()) {
         backend_types = {wgpu::BackendType::Vulkan};
@@ -1990,7 +1990,7 @@ WebGPUDecoderImpl::AssociateMailboxDawn(
   }
 
 #if !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_APPLE) && \
-    !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_LINUX)
+    !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   if (usage & wgpu::TextureUsage::StorageBinding) {
     LOG(ERROR) << "AssociateMailbox: wgpu::TextureUsage::StorageBinding is NOT "
                   "supported yet on this platform.";
