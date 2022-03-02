--- gpu/ipc/service/gpu_init.cc.orig	2022-02-28 16:54:41 UTC
+++ gpu/ipc/service/gpu_init.cc
@@ -122,7 +122,7 @@ void InitializePlatformOverlaySettings(GPUInfo* gpu_in
 }
 
 #if BUILDFLAG(IS_CHROMEOS_LACROS) || \
-    (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMECAST))
+    (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMECAST)) && !BUILDFLAG(IS_BSD)
 bool CanAccessNvidiaDeviceFile() {
   bool res = true;
   base::ScopedBlockingCall scoped_blocking_call(FROM_HERE,
@@ -220,7 +220,7 @@ bool GpuInit::InitializeAndStartSandbox(base::CommandL
     device_perf_info_ = device_perf_info;
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_BSD)
   if (gpu_info_.gpu.vendor_id == 0x10de &&  // NVIDIA
       gpu_info_.gpu.driver_vendor == "NVIDIA" && !CanAccessNvidiaDeviceFile())
     return false;
@@ -284,7 +284,7 @@ bool GpuInit::InitializeAndStartSandbox(base::CommandL
   delayed_watchdog_enable = true;
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // PreSandbox is mainly for resource handling and not related to the GPU
   // driver, it doesn't need the GPU watchdog. The loadLibrary may take long
   // time that killing and restarting the GPU process will not help.
@@ -324,7 +324,7 @@ bool GpuInit::InitializeAndStartSandbox(base::CommandL
   }
 
   bool attempted_startsandbox = false;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // On Chrome OS ARM Mali, GPU driver userspace creates threads when
   // initializing a GL context, so start the sandbox early.
   // TODO(zmo): Need to collect OS version before this.
@@ -373,7 +373,7 @@ bool GpuInit::InitializeAndStartSandbox(base::CommandL
   }
   if (gl_initialized && gl_use_swiftshader_ &&
       !gl::IsSoftwareGLImplementation(gl::GetGLImplementationParts())) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     VLOG(1) << "Quit GPU process launch to fallback to SwiftShader cleanly "
             << "on Linux";
     return false;
@@ -407,7 +407,7 @@ bool GpuInit::InitializeAndStartSandbox(base::CommandL
     }
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // The ContentSandboxHelper is currently the only one implementation of
   // GpuSandboxHelper and it has no dependency. Except on Linux where
   // VaapiWrapper checks the GL implementation to determine which display
@@ -460,7 +460,7 @@ bool GpuInit::InitializeAndStartSandbox(base::CommandL
           command_line, gpu_feature_info_,
           gpu_preferences_.disable_software_rasterizer, false);
       if (gl_use_swiftshader_) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
         VLOG(1) << "Quit GPU process launch to fallback to SwiftShader cleanly "
                 << "on Linux";
         return false;
@@ -566,7 +566,7 @@ bool GpuInit::InitializeAndStartSandbox(base::CommandL
 
   InitializePlatformOverlaySettings(&gpu_info_, gpu_feature_info_);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Driver may create a compatibility profile context when collect graphics
   // information on Linux platform. Try to collect graphics information
   // based on core profile context after disabling platform extensions.
@@ -799,7 +799,7 @@ void GpuInit::InitializeInProcess(base::CommandLine* c
 
   InitializePlatformOverlaySettings(&gpu_info_, gpu_feature_info_);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Driver may create a compatibility profile context when collect graphics
   // information on Linux platform. Try to collect graphics information
   // based on core profile context after disabling platform extensions.
