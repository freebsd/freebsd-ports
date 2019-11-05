--- gpu/ipc/service/gpu_init.cc.orig	2019-10-21 19:06:35 UTC
+++ gpu/ipc/service/gpu_init.cc
@@ -109,7 +109,7 @@ void InitializePlatformOverlaySettings(GPUInfo* gpu_in
 #endif
 }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(IS_CHROMECAST)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(IS_CHROMECAST)) || defined(OS_BSD)
 bool CanAccessNvidiaDeviceFile() {
   bool res = true;
   base::ScopedBlockingCall scoped_blocking_call(FROM_HERE,
@@ -120,7 +120,7 @@ bool CanAccessNvidiaDeviceFile() {
   }
   return res;
 }
-#endif  // OS_LINUX && !OS_CHROMEOS && !IS_CHROMECAST
+#endif  // (OS_LINUX && !OS_CHROMEOS && !IS_CHROMECAST) || OS_BSD
 
 class GpuWatchdogInit {
  public:
@@ -165,7 +165,7 @@ bool GpuInit::InitializeAndStartSandbox(base::CommandL
   // crash during feature collection.
   gpu::SetKeysForCrashLogging(gpu_info_);
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   if (gpu_info_.gpu.vendor_id == 0x10de &&  // NVIDIA
       gpu_info_.gpu.driver_vendor == "NVIDIA" && !CanAccessNvidiaDeviceFile())
     return false;
@@ -246,7 +246,7 @@ bool GpuInit::InitializeAndStartSandbox(base::CommandL
   sandbox_helper_->PreSandboxStartup();
 
   bool attempted_startsandbox = false;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) && !defined(OS_BSD)
   // On Chrome OS ARM Mali, GPU driver userspace creates threads when
   // initializing a GL context, so start the sandbox early.
   // TODO(zmo): Need to collect OS version before this.
@@ -255,7 +255,7 @@ bool GpuInit::InitializeAndStartSandbox(base::CommandL
         watchdog_thread_.get(), &gpu_info_, gpu_preferences_);
     attempted_startsandbox = true;
   }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) && !defined(OS_BSD)
 
   base::TimeTicks before_initialize_one_off = base::TimeTicks::Now();
 
@@ -304,14 +304,14 @@ bool GpuInit::InitializeAndStartSandbox(base::CommandL
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
   if (!gl_initialized)
     gl_initialized = gl::init::InitializeGLNoExtensionsOneOff();
@@ -337,7 +337,7 @@ bool GpuInit::InitializeAndStartSandbox(base::CommandL
         command_line, gpu_feature_info_,
         gpu_preferences_.disable_software_rasterizer, false);
     if (use_swiftshader) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
       VLOG(1) << "Quit GPU process launch to fallback to SwiftShader cleanly "
               << "on Linux";
       return false;
@@ -348,7 +348,7 @@ bool GpuInit::InitializeAndStartSandbox(base::CommandL
                 << "failed";
         return false;
       }
-#endif  // OS_LINUX
+#endif  // OS_LINUX || OS_BSD
     }
   }
 
@@ -377,7 +377,7 @@ bool GpuInit::InitializeAndStartSandbox(base::CommandL
 
   InitializePlatformOverlaySettings(&gpu_info_);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Driver may create a compatibility profile context when collect graphics
   // information on Linux platform. Try to collect graphics information
   // based on core profile context after disabling platform extensions.
@@ -396,7 +396,7 @@ bool GpuInit::InitializeAndStartSandbox(base::CommandL
       return false;
     }
   }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
   if (use_swiftshader) {
     AdjustInfoToSwiftShader();
@@ -569,7 +569,7 @@ void GpuInit::InitializeInProcess(base::CommandLine* c
 
   InitializePlatformOverlaySettings(&gpu_info_);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Driver may create a compatibility profile context when collect graphics
   // information on Linux platform. Try to collect graphics information
   // based on core profile context after disabling platform extensions.
@@ -589,7 +589,7 @@ void GpuInit::InitializeInProcess(base::CommandLine* c
       }
     }
   }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
   if (use_swiftshader) {
     AdjustInfoToSwiftShader();
