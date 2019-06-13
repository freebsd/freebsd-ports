--- gpu/ipc/service/gpu_init.cc.orig	2019-06-04 18:55:24 UTC
+++ gpu/ipc/service/gpu_init.cc
@@ -88,7 +88,7 @@ void InitializeDirectCompositionOverlaySupport(GPUInfo
 }
 #endif  // defined(OS_WIN)
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(IS_CHROMECAST)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(IS_CHROMECAST)) || defined(OS_BSD)
 bool CanAccessNvidiaDeviceFile() {
   bool res = true;
   base::ScopedBlockingCall scoped_blocking_call(FROM_HERE,
@@ -99,7 +99,7 @@ bool CanAccessNvidiaDeviceFile() {
   }
   return res;
 }
-#endif  // OS_LINUX && !OS_CHROMEOS && !IS_CHROMECAST
+#endif  // (OS_LINUX && !OS_CHROMEOS && !IS_CHROMECAST) || OS_BSD
 
 }  // namespace
 
@@ -131,7 +131,7 @@ bool GpuInit::InitializeAndStartSandbox(base::CommandL
   // crash during feature collection.
   gpu::SetKeysForCrashLogging(gpu_info_);
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   if (gpu_info_.gpu.vendor_id == 0x10de &&  // NVIDIA
       gpu_info_.gpu.driver_vendor == "NVIDIA" && !CanAccessNvidiaDeviceFile())
     return false;
@@ -201,7 +201,7 @@ bool GpuInit::InitializeAndStartSandbox(base::CommandL
   sandbox_helper_->PreSandboxStartup();
 
   bool attempted_startsandbox = false;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) && !defined(OS_BSD)
   // On Chrome OS ARM Mali, GPU driver userspace creates threads when
   // initializing a GL context, so start the sandbox early.
   // TODO(zmo): Need to collect OS version before this.
@@ -210,7 +210,7 @@ bool GpuInit::InitializeAndStartSandbox(base::CommandL
         watchdog_thread_.get(), &gpu_info_, gpu_preferences_);
     attempted_startsandbox = true;
   }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) && !defined(OS_BSD)
 
   base::TimeTicks before_initialize_one_off = base::TimeTicks::Now();
 
@@ -307,7 +307,7 @@ bool GpuInit::InitializeAndStartSandbox(base::CommandL
   InitializeDirectCompositionOverlaySupport(&gpu_info_);
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Driver may create a compatibility profile context when collect graphics
   // information on Linux platform. Try to collect graphics information
   // based on core profile context after disabling platform extensions.
@@ -329,7 +329,7 @@ bool GpuInit::InitializeAndStartSandbox(base::CommandL
       }
     }
   }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
   if (use_swiftshader) {
     AdjustInfoToSwiftShader();
@@ -489,7 +489,7 @@ void GpuInit::InitializeInProcess(base::CommandLine* c
   InitializeDirectCompositionOverlaySupport(&gpu_info_);
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Driver may create a compatibility profile context when collect graphics
   // information on Linux platform. Try to collect graphics information
   // based on core profile context after disabling platform extensions.
@@ -509,7 +509,7 @@ void GpuInit::InitializeInProcess(base::CommandLine* c
       }
     }
   }
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
   if (use_swiftshader) {
     AdjustInfoToSwiftShader();
