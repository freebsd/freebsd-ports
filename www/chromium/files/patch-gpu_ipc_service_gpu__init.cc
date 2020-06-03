--- gpu/ipc/service/gpu_init.cc.orig	2020-05-13 18:40:32 UTC
+++ gpu/ipc/service/gpu_init.cc
@@ -92,7 +92,7 @@ void InitializePlatformOverlaySettings(GPUInfo* gpu_in
 #endif
 }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS) && !BUILDFLAG(IS_CHROMECAST)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS) && !BUILDFLAG(IS_CHROMECAST)) || defined(OS_BSD)
 bool CanAccessNvidiaDeviceFile() {
   bool res = true;
   base::ScopedBlockingCall scoped_blocking_call(FROM_HERE,
@@ -103,7 +103,7 @@ bool CanAccessNvidiaDeviceFile() {
   }
   return res;
 }
-#endif  // OS_LINUX && !OS_CHROMEOS && !BUILDFLAG(IS_CHROMECAST)
+#endif  // (OS_LINUX && !OS_CHROMEOS && !BUILDFLAG(IS_CHROMECAST)) || defined(OS_BSD)
 
 class GpuWatchdogInit {
  public:
@@ -161,7 +161,7 @@ bool GpuInit::InitializeAndStartSandbox(base::CommandL
   gpu_info_.subpixel_font_rendering = true;
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   if (gpu_info_.gpu.vendor_id == 0x10de &&  // NVIDIA
       gpu_info_.gpu.driver_vendor == "NVIDIA" && !CanAccessNvidiaDeviceFile())
     return false;
@@ -213,7 +213,7 @@ bool GpuInit::InitializeAndStartSandbox(base::CommandL
   delayed_watchdog_enable = true;
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // PreSandbox is mainly for resource handling and not related to the GPU
   // driver, it doesn't need the GPU watchdog. The loadLibrary may take long
   // time that killing and restarting the GPU process will not help.
@@ -258,7 +258,7 @@ bool GpuInit::InitializeAndStartSandbox(base::CommandL
   }
 
   bool attempted_startsandbox = false;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) && !defined(OS_BSD)
   // On Chrome OS ARM Mali, GPU driver userspace creates threads when
   // initializing a GL context, so start the sandbox early.
   // TODO(zmo): Need to collect OS version before this.
@@ -267,7 +267,7 @@ bool GpuInit::InitializeAndStartSandbox(base::CommandL
         watchdog_thread_.get(), &gpu_info_, gpu_preferences_);
     attempted_startsandbox = true;
   }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) && !defined(OS_BSD)
 
   base::TimeTicks before_initialize_one_off = base::TimeTicks::Now();
 
@@ -291,14 +291,14 @@ bool GpuInit::InitializeAndStartSandbox(base::CommandL
   }
   if (gl_initialized && use_swiftshader &&
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
@@ -324,7 +324,7 @@ bool GpuInit::InitializeAndStartSandbox(base::CommandL
     }
   }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) && !defined(OS_BSD)
   // The ContentSandboxHelper is currently the only one implementation of
   // gpu::GpuSandboxHelper and it has no dependency. Except on Linux where
   // VaapiWrapper checks the GL implementation to determine which display
@@ -375,7 +375,7 @@ bool GpuInit::InitializeAndStartSandbox(base::CommandL
           command_line, gpu_feature_info_,
           gpu_preferences_.disable_software_rasterizer, false);
       if (use_swiftshader) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
         VLOG(1) << "Quit GPU process launch to fallback to SwiftShader cleanly "
                 << "on Linux";
         return false;
@@ -389,7 +389,7 @@ bool GpuInit::InitializeAndStartSandbox(base::CommandL
               << "failed";
           return false;
         }
-#endif  // OS_LINUX
+#endif  // OS_LINUX || OS_BSD
       }
     } else {  // use_swiftshader == true
       switch (gpu_preferences_.use_vulkan) {
@@ -445,7 +445,7 @@ bool GpuInit::InitializeAndStartSandbox(base::CommandL
 
   InitializePlatformOverlaySettings(&gpu_info_);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Driver may create a compatibility profile context when collect graphics
   // information on Linux platform. Try to collect graphics information
   // based on core profile context after disabling platform extensions.
@@ -464,7 +464,7 @@ bool GpuInit::InitializeAndStartSandbox(base::CommandL
       return false;
     }
   }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
   if (use_swiftshader) {
     AdjustInfoToSwiftShader();
@@ -631,7 +631,7 @@ void GpuInit::InitializeInProcess(base::CommandLine* c
 
   InitializePlatformOverlaySettings(&gpu_info_);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Driver may create a compatibility profile context when collect graphics
   // information on Linux platform. Try to collect graphics information
   // based on core profile context after disabling platform extensions.
@@ -651,7 +651,7 @@ void GpuInit::InitializeInProcess(base::CommandLine* c
       }
     }
   }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
   if (use_swiftshader) {
     AdjustInfoToSwiftShader();
