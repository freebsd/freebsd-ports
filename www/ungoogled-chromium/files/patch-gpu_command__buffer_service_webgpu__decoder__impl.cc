--- gpu/command_buffer/service/webgpu_decoder_impl.cc.orig	2026-05-09 18:09:27 UTC
+++ gpu/command_buffer/service/webgpu_decoder_impl.cc
@@ -1775,7 +1775,7 @@ wgpu::Adapter WebGPUDecoderImpl::CreatePreferredAdapte
       backend_types = {wgpu::BackendType::D3D12};
 #elif BUILDFLAG(IS_APPLE)
       backend_types = {wgpu::BackendType::Metal};
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       if (shared_context_state_->GrContextIsVulkan() ||
           webgpu_on_vk_gl_interop_ ||
           shared_context_state_->IsGraphiteDawnVulkan()) {
@@ -2101,7 +2101,7 @@ WebGPUDecoderImpl::AssociateMailboxDawn(
   }
 
 #if !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_APPLE) && \
-    !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_LINUX)
+    !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   if (usage & wgpu::TextureUsage::StorageBinding) {
     LOG(ERROR) << "AssociateMailbox: wgpu::TextureUsage::StorageBinding is NOT "
                   "supported yet on this platform.";
