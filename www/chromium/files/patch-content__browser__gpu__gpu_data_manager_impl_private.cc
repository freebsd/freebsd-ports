--- content/browser/gpu/gpu_data_manager_impl_private.cc.orig	2016-03-04 22:36:56.082636647 +0100
+++ content/browser/gpu/gpu_data_manager_impl_private.cc	2016-03-04 22:37:11.778635557 +0100
@@ -483,8 +483,10 @@
   gpu_info.gl_renderer = gl_renderer;
   gpu_info.gl_version = gl_version;
 
+#if !defined(OS_FREEBSD)
   gpu::IdentifyActiveGPU(&gpu_info);
   gpu::CollectDriverInfoGL(&gpu_info);
+#endif
 
   UpdateGpuInfo(gpu_info);
   UpdateGpuSwitchingManager(gpu_info);
@@ -513,10 +515,12 @@
     // Also declare the driver_vendor to be osmesa to be able to specify
     // exceptions based on driver_vendor==osmesa for some blacklist rules.
     gpu_info.driver_vendor = gfx::kGLImplementationOSMesaName;
+#ifndef __FreeBSD__
   } else {
     TRACE_EVENT0("startup",
       "GpuDataManagerImpl::Initialize:CollectBasicGraphicsInfo");
     gpu::CollectBasicGraphicsInfo(&gpu_info);
+#endif
   }
 #if defined(ARCH_CPU_X86_FAMILY)
   if (!gpu_info.gpu.vendor_id || !gpu_info.gpu.device_id) {
@@ -575,7 +579,9 @@
     return;
 
   bool was_info_available = IsCompleteGpuInfoAvailable();
+#ifndef __FreeBSD__
   gpu::MergeGPUInfo(&gpu_info_, gpu_info);
+#endif
   if (IsCompleteGpuInfoAvailable()) {
     complete_gpu_info_already_requested_ = true;
   } else if (was_info_available) {
