--- services/ui/gpu/gpu_service.cc.orig	2017-06-05 19:03:11 UTC
+++ services/ui/gpu/gpu_service.cc
@@ -269,7 +269,7 @@ void GpuService::RequestCompleteGpuInfo(
   }
   UpdateGpuInfoPlatform();
   callback.Run(gpu_info_);
-#if defined(OS_WIN)
+#if defined(OS_WIN) && !defined(OS_BSD)
   if (!in_host_process_) {
     // The unsandboxed GPU process fulfilled its duty. Rest in peace.
     base::MessageLoop::current()->QuitWhenIdle();
@@ -305,7 +305,7 @@ void GpuService::UpdateGpuInfoPlatform() {
   }
   gpu::SetKeysForCrashLogging(gpu_info_);
 }
-#elif defined(OS_WIN)
+#elif defined(OS_WIN) && !defined(OS_BSD)
 void GpuService::UpdateGpuInfoPlatform() {
   DCHECK(main_runner_->BelongsToCurrentThread());
   // GPU full info collection should only happen on un-sandboxed GPU process
@@ -353,7 +353,7 @@ void GpuService::StoreShaderToDisk(int client_id,
   (*gpu_host_)->StoreShaderToDisk(client_id, key, shader);
 }
 
-#if defined(OS_WIN)
+#if defined(OS_WIN) && !defined(OS_BSD)
 void GpuService::SendAcceleratedSurfaceCreatedChildWindow(
     gpu::SurfaceHandle parent_window,
     gpu::SurfaceHandle child_window) {
