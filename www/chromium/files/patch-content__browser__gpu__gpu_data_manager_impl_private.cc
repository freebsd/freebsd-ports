--- content/browser/gpu/gpu_data_manager_impl_private.cc.orig	2014-10-10 08:54:14 UTC
+++ content/browser/gpu/gpu_data_manager_impl_private.cc
@@ -471,7 +471,9 @@
   gpu_info.gl_renderer = gl_renderer;
   gpu_info.gl_version = gl_version;
 
+#if !defined(OS_FREEBSD)
   gpu::CollectDriverInfoGL(&gpu_info);
+#endif
 
   UpdateGpuInfo(gpu_info);
   UpdateGpuSwitchingManager(gpu_info);
@@ -514,10 +516,12 @@
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
@@ -569,7 +573,9 @@
   if (use_swiftshader_ || ShouldUseWarp())
     return;
 
+#ifndef __FreeBSD__
   gpu::MergeGPUInfo(&gpu_info_, gpu_info);
+#endif
   if (IsCompleteGpuInfoAvailable())
     complete_gpu_info_already_requested_ = true;
 
