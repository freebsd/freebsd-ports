--- src/3rdparty/chromium/services/ui/surfaces/surfaces_context_provider.cc.orig	2017-02-02 02:02:57 UTC
+++ src/3rdparty/chromium/services/ui/surfaces/surfaces_context_provider.cc
@@ -78,7 +78,7 @@ bool SurfacesContextProvider::BindToCurr
   gpu::CommandBuffer* command_buffer = command_buffer_proxy_impl_.get();
 
   gles2_helper_.reset(new gpu::gles2::GLES2CmdHelper(command_buffer));
-  constexpr gpu::SharedMemoryLimits default_limits;
+  constexpr gpu::SharedMemoryLimits default_limits = gpu::SharedMemoryLimits();
   if (!gles2_helper_->Initialize(default_limits.command_buffer_size))
     return false;
   gles2_helper_->SetAutomaticFlushes(false);
