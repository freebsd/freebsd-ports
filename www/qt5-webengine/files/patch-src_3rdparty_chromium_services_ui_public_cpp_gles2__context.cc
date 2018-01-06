--- src/3rdparty/chromium/services/ui/public/cpp/gles2_context.cc.orig	2017-02-02 02:02:57 UTC
+++ src/3rdparty/chromium/services/ui/public/cpp/gles2_context.cc
@@ -46,7 +46,7 @@ bool GLES2Context::Initialize(
   gpu::CommandBuffer* command_buffer = command_buffer_proxy_impl_.get();
   gpu::GpuControl* gpu_control = command_buffer_proxy_impl_.get();
 
-  constexpr gpu::SharedMemoryLimits default_limits;
+  constexpr gpu::SharedMemoryLimits default_limits = gpu::SharedMemoryLimits();
   gles2_helper_.reset(new gpu::gles2::GLES2CmdHelper(command_buffer));
   if (!gles2_helper_->Initialize(default_limits.command_buffer_size))
     return false;
