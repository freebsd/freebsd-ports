--- gpu/ipc/service/gpu_init.cc.orig	2018-02-24 16:25:15.000000000 +0100
+++ gpu/ipc/service/gpu_init.cc	2018-03-04 02:41:07.510363000 +0100
@@ -37,7 +37,7 @@
 namespace gpu {
 
 namespace {
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
 void CollectGraphicsInfo(GPUInfo* gpu_info) {
   DCHECK(gpu_info);
 #if defined(OS_FUCHSIA)
@@ -77,9 +77,9 @@
   }
 #endif  // defined(OS_FUCHSIA)
 }
-#endif  // defined(OS_MACOSX)
+#endif  // defined(OS_MACOSX) && defined(OS_BSD)
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_BSD)
 bool CanAccessNvidiaDeviceFile() {
   bool res = true;
   base::AssertBlockingAllowed();
@@ -120,7 +120,7 @@
   // crash during feature collection.
   gpu::SetKeysForCrashLogging(gpu_info_);
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_BSD)
   if (gpu_info_.gpu.vendor_id == 0x10de &&  // NVIDIA
       gpu_info_.driver_vendor == "NVIDIA" && !CanAccessNvidiaDeviceFile())
     return false;
@@ -183,7 +183,7 @@
   sandbox_helper_->PreSandboxStartup();
 
   bool attempted_startsandbox = false;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) && !defined(OS_BSD)
   // On Chrome OS ARM Mali, GPU driver userspace creates threads when
   // initializing a GL context, so start the sandbox early.
   // TODO(zmo): Need to collect OS version before this.
@@ -222,7 +222,7 @@
   // multiple seconds to finish, which in turn cause the GPU process to crash.
   // By skipping the following code on Mac, we don't really lose anything,
   // because the basic GPU information is passed down from the host process.
-#if !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   CollectGraphicsInfo(&gpu_info_);
   if (gpu_info_.context_info_state == gpu::kCollectInfoFatalFailure)
     return false;
@@ -308,7 +308,7 @@
     return;
   }
 
-#if !defined(OS_ANDROID)
+#if !defined(OS_ANDROID) && !defined(OS_BSD)
   gpu::CollectContextGraphicsInfo(&gpu_info_);
   gpu_feature_info_ = gpu::ComputeGpuFeatureInfo(gpu_info_, command_line);
 #endif
