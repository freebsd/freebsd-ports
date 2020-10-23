--- gpu/ipc/service/gpu_init.cc.orig	2020-09-08 19:14:06 UTC
+++ gpu/ipc/service/gpu_init.cc
@@ -94,7 +94,7 @@ void InitializePlatformOverlaySettings(GPUInfo* gpu_in
 #endif
 }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS) && !BUILDFLAG(IS_CHROMECAST)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS) && !BUILDFLAG(IS_CHROMECAST)) || defined(OS_BSD)
 bool CanAccessNvidiaDeviceFile() {
   bool res = true;
   base::ScopedBlockingCall scoped_blocking_call(FROM_HERE,
@@ -105,7 +105,7 @@ bool CanAccessNvidiaDeviceFile() {
   }
   return res;
 }
-#endif  // OS_LINUX && !OS_CHROMEOS && !BUILDFLAG(IS_CHROMECAST)
+#endif  // (OS_LINUX && !OS_CHROMEOS && !BUILDFLAG(IS_CHROMECAST)) || defined(OS_BSD)
 
 class GpuWatchdogInit {
  public:
@@ -178,7 +178,7 @@ bool GpuInit::InitializeAndStartSandbox(base::CommandL
     device_perf_info_ = device_perf_info;
   }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   if (gpu_info_.gpu.vendor_id == 0x10de &&  // NVIDIA
       gpu_info_.gpu.driver_vendor == "NVIDIA" && !CanAccessNvidiaDeviceFile())
     return false;
@@ -230,7 +230,7 @@ bool GpuInit::InitializeAndStartSandbox(base::CommandL
   delayed_watchdog_enable = true;
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // PreSandbox is mainly for resource handling and not related to the GPU
   // driver, it doesn't need the GPU watchdog. The loadLibrary may take long
   // time that killing and restarting the GPU process will not help.
@@ -275,7 +275,7 @@ bool GpuInit::InitializeAndStartSandbox(base::CommandL
   }
 
   bool attempted_startsandbox = false;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) && !defined(OS_BSD)
   // On Chrome OS ARM Mali, GPU driver userspace creates threads when
   // initializing a GL context, so start the sandbox early.
   // TODO(zmo): Need to collect OS version before this.
@@ -284,7 +284,7 @@ bool GpuInit::InitializeAndStartSandbox(base::CommandL
         watchdog_thread_.get(), &gpu_info_, gpu_preferences_);
     attempted_startsandbox = true;
   }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) && !defined(OS_BSD)
 
   base::TimeTicks before_initialize_one_off = base::TimeTicks::Now();
 
@@ -307,14 +307,14 @@ bool GpuInit::InitializeAndStartSandbox(base::CommandL
   }
   if (gl_initialized && gl_use_swiftshader_ &&
       gl::GetGLImplementation() != gl::kGLImplementationSwiftShaderGL) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     VLOG(1) << "Quit GPU process launch to fallback to SwiftShader cleanly "
             << "on Linux";
     return false;
 #else
     gl::init::ShutdownGL(true);
     gl_initialized = false;
-#endif  // OS_LINUX
+#endif  // OS_LINUX || OS_BSD
   }
 
   if (!gl_initialized) {
@@ -340,7 +340,7 @@ bool GpuInit::InitializeAndStartSandbox(base::CommandL
     }
   }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) && !defined(OS_BSD)
   // The ContentSandboxHelper is currently the only one implementation of
   // GpuSandboxHelper and it has no dependency. Except on Linux where
   // VaapiWrapper checks the GL implementation to determine which display
@@ -392,7 +392,7 @@ bool GpuInit::InitializeAndStartSandbox(base::CommandL
           command_line, gpu_feature_info_,
           gpu_preferences_.disable_software_rasterizer, false);
       if (gl_use_swiftshader_) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
         VLOG(1) << "Quit GPU process launch to fallback to SwiftShader cleanly "
                 << "on Linux";
         return false;
@@ -406,7 +406,7 @@ bool GpuInit::InitializeAndStartSandbox(base::CommandL
               << "failed";
           return false;
         }
-#endif  // OS_LINUX
+#endif  // OS_LINUX || OS_BSD
       }
     } else {  // gl_use_swiftshader_ == true
       switch (gpu_preferences_.use_vulkan) {
@@ -482,7 +482,7 @@ bool GpuInit::InitializeAndStartSandbox(base::CommandL
 
   InitializePlatformOverlaySettings(&gpu_info_);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Driver may create a compatibility profile context when collect graphics
   // information on Linux platform. Try to collect graphics information
   // based on core profile context after disabling platform extensions.
@@ -501,7 +501,7 @@ bool GpuInit::InitializeAndStartSandbox(base::CommandL
       return false;
     }
   }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
   if (gl_use_swiftshader_) {
     AdjustInfoToSwiftShader();
@@ -667,7 +667,7 @@ void GpuInit::InitializeInProcess(base::CommandLine* c
 
   InitializePlatformOverlaySettings(&gpu_info_);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Driver may create a compatibility profile context when collect graphics
   // information on Linux platform. Try to collect graphics information
   // based on core profile context after disabling platform extensions.
@@ -687,7 +687,7 @@ void GpuInit::InitializeInProcess(base::CommandLine* c
       }
     }
   }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
   if (gl_use_swiftshader_) {
     AdjustInfoToSwiftShader();
