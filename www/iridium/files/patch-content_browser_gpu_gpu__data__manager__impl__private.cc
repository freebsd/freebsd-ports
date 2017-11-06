--- content/browser/gpu/gpu_data_manager_impl_private.cc.orig	2017-04-19 19:06:33 UTC
+++ content/browser/gpu/gpu_data_manager_impl_private.cc
@@ -396,7 +396,7 @@ bool GpuDataManagerImplPrivate::GpuAcces
     // strings even if all features are blacklisted. If all GPU features are
     // disabled, the GPU process will only initialize GL bindings, create a GL
     // context, and collect full GPU info.
-#if !defined(OS_LINUX)
+#if !defined(OS_LINUX) || !defined(OS_BSD)
     if (reason) {
       *reason = "All GPU features are blacklisted.";
     }
@@ -513,8 +513,10 @@ void GpuDataManagerImplPrivate::SetGLStr
   gpu_info.gl_renderer = gl_renderer;
   gpu_info.gl_version = gl_version;
 
+#if !defined(OS_BSD)
   gpu::IdentifyActiveGPU(&gpu_info);
   gpu::CollectDriverInfoGL(&gpu_info);
+#endif
 
   UpdateGpuInfo(gpu_info);
   UpdateGpuSwitchingManager(gpu_info);
@@ -572,10 +574,12 @@ void GpuDataManagerImplPrivate::Initiali
     // Skip collecting the basic driver info if SetGpuInfo() is already called.
     if (IsCompleteGpuInfoAvailable()) {
       gpu_info = gpu_info_;
+#ifndef OS_BSD
     } else {
       TRACE_EVENT0("startup",
                    "GpuDataManagerImpl::Initialize:CollectBasicGraphicsInfo");
       gpu::CollectBasicGraphicsInfo(&gpu_info);
+#endif
     }
 
     if (command_line->HasSwitch(switches::kGpuTestingVendorId) &&
@@ -686,7 +690,9 @@ void GpuDataManagerImplPrivate::UpdateGp
     return;
 
   bool was_info_available = IsCompleteGpuInfoAvailable();
+#ifndef OS_BSD
   gpu::MergeGPUInfo(&gpu_info_, gpu_info);
+#endif
   if (IsCompleteGpuInfoAvailable()) {
     complete_gpu_info_already_requested_ = true;
   } else if (was_info_available) {
