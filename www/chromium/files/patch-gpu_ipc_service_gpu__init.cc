--- gpu/ipc/service/gpu_init.cc.orig	2017-12-15 02:04:19.000000000 +0100
+++ gpu/ipc/service/gpu_init.cc	2017-12-31 04:40:00.427872000 +0100
@@ -37,7 +37,7 @@
 namespace gpu {
 
 namespace {
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
 void CollectGraphicsInfo(GPUInfo* gpu_info) {
   DCHECK(gpu_info);
 #if defined(OS_FUCHSIA)
@@ -80,9 +80,9 @@
   }
 #endif  // defined(OS_FUCHSIA)
 }
-#endif  // defined(OS_MACOSX)
+#endif  // defined(OS_MACOSX) && defined(OS_BSD)
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_BSD)
 bool CanAccessNvidiaDeviceFile() {
   bool res = true;
   base::ThreadRestrictions::AssertIOAllowed();
@@ -116,7 +116,7 @@
   // passing from browser process.
   GetGpuInfoFromCommandLine(*command_line, &gpu_info_);
 #endif  // OS_ANDROID
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_BSD)
   if (gpu_info_.gpu.vendor_id == 0x10de &&  // NVIDIA
       gpu_info_.driver_vendor == "NVIDIA" && !CanAccessNvidiaDeviceFile())
     return false;
@@ -213,7 +213,7 @@
   // multiple seconds to finish, which in turn cause the GPU process to crash.
   // By skipping the following code on Mac, we don't really lose anything,
   // because the basic GPU information is passed down from the host process.
-#if !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   CollectGraphicsInfo(&gpu_info_);
   if (gpu_info_.context_info_state == gpu::kCollectInfoFatalFailure)
     return false;
@@ -288,7 +288,7 @@
     return;
   }
 
-#if !defined(OS_ANDROID)
+#if !defined(OS_ANDROID) && !defined(OS_BSD)
   gpu::CollectContextGraphicsInfo(&gpu_info_);
   gpu_feature_info_ = gpu::ComputeGpuFeatureInfo(gpu_info_, command_line);
 #endif
