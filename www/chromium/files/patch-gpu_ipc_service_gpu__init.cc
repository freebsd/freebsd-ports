--- gpu/ipc/service/gpu_init.cc.orig	2018-03-20 23:05:26.000000000 +0100
+++ gpu/ipc/service/gpu_init.cc	2018-03-26 13:24:11.299258000 +0200
@@ -41,7 +41,7 @@
 #if !defined(OS_MACOSX)
 void CollectGraphicsInfo(GPUInfo* gpu_info) {
   DCHECK(gpu_info);
-#if defined(OS_FUCHSIA)
+#if defined(OS_FUCHSIA) || defined(OS_BSD)
   // TODO(crbug.com/707031): Implement this.
   NOTIMPLEMENTED();
   return;
@@ -84,7 +84,7 @@
 }
 #endif  // defined(OS_MACOSX)
 
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
@@ -179,7 +179,7 @@
   sandbox_helper_->PreSandboxStartup();
 
   bool attempted_startsandbox = false;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) && !defined(OS_BSD)
   // On Chrome OS ARM Mali, GPU driver userspace creates threads when
   // initializing a GL context, so start the sandbox early.
   // TODO(zmo): Need to collect OS version before this.
