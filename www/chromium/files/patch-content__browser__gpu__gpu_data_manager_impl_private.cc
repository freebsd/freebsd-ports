--- content/browser/gpu/gpu_data_manager_impl_private.cc.orig	2014-10-02 17:39:47 UTC
+++ content/browser/gpu/gpu_data_manager_impl_private.cc
@@ -454,7 +454,9 @@
   gpu_info.gl_renderer = gl_renderer;
   gpu_info.gl_version = gl_version;
 
+#if !defined(OS_FREEBSD) //XXX(rene) hack
   gpu::CollectDriverInfoGL(&gpu_info);
+#endif
 
   UpdateGpuInfo(gpu_info);
   UpdateGpuSwitchingManager(gpu_info);
@@ -497,10 +499,13 @@
     // Also declare the driver_vendor to be osmesa to be able to specify
     // exceptions based on driver_vendor==osmesa for some blacklist rules.
     gpu_info.driver_vendor = gfx::kGLImplementationOSMesaName;
+#ifndef __FreeBSD__
   } else {
+    //XXX(rene) hack
     TRACE_EVENT0("startup",
       "GpuDataManagerImpl::Initialize:CollectBasicGraphicsInfo");
     gpu::CollectBasicGraphicsInfo(&gpu_info);
+#endif
   }
 #if defined(ARCH_CPU_X86_FAMILY)
   if (!gpu_info.gpu.vendor_id || !gpu_info.gpu.device_id)
@@ -547,8 +552,10 @@
   // No further update of gpu_info if falling back to SwiftShader.
   if (use_swiftshader_)
     return;
-
+#ifndef __FreeBSD__
+  // XXX(rene) hack
   gpu::MergeGPUInfo(&gpu_info_, gpu_info);
+#endif
   complete_gpu_info_already_requested_ =
       complete_gpu_info_already_requested_ || gpu_info_.finalized;
 
