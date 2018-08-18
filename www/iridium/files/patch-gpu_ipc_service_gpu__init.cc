--- gpu/ipc/service/gpu_init.cc.orig	2018-06-13 00:10:19.000000000 +0200
+++ gpu/ipc/service/gpu_init.cc	2018-07-19 14:45:14.322631000 +0200
@@ -70,7 +70,7 @@
 }
 #endif  // defined(OS_MACOSX)
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(IS_CHROMECAST)
+#if defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(IS_CHROMECAST) && !defined(OS_BSD)
 bool CanAccessNvidiaDeviceFile() {
   bool res = true;
   base::AssertBlockingAllowed();
@@ -106,7 +106,7 @@
   // crash during feature collection.
   gpu::SetKeysForCrashLogging(gpu_info_);
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_BSD)
   if (gpu_info_.gpu.vendor_id == 0x10de &&  // NVIDIA
       gpu_info_.driver_vendor == "NVIDIA" && !CanAccessNvidiaDeviceFile())
     return false;
@@ -172,7 +172,7 @@
   sandbox_helper_->PreSandboxStartup();
 
   bool attempted_startsandbox = false;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) && !defined(OS_BSD)
   // On Chrome OS ARM Mali, GPU driver userspace creates threads when
   // initializing a GL context, so start the sandbox early.
   // TODO(zmo): Need to collect OS version before this.
