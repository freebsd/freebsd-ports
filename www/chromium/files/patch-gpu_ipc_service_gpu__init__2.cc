--- gpu/ipc/service/gpu_init_2.cc.orig	2026-11-19 12:25:27 UTC
+++ gpu/ipc/service/gpu_init_2.cc
@@ -597,7 +597,7 @@ void GpuInit2::InitializeInProcess(base::CommandLine* 
     }
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Driver may create a compatibility profile context when collect graphics
   // information on Linux platform. Try to collect graphics information
   // based on core profile context after disabling platform extensions.
@@ -748,7 +748,7 @@ void GpuInit2::MaybeFallbackToSwiftShaderEarly(InitSta
 }
 
 void GpuInit2::StartWatchdogAndMaybeSandboxEarly(InitState& state) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   bool gpu_sandbox_start_early = gpu_preferences_.gpu_sandbox_start_early;
 #else   // !(BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
   // For some reasons MacOSX's VideoToolbox might crash when called after
@@ -774,7 +774,7 @@ void GpuInit2::StartWatchdogAndMaybeSandboxEarly(InitS
     state.watchdog.Create(gl_use_swiftshader_);
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // On Chrome OS ARM Mali, GPU driver userspace creates threads when
   // initializing a GL context, so start the sandbox early.
   // TODO(zmo): Need to collect OS version before this.
@@ -801,7 +801,7 @@ bool GpuInit2::InitializeGLBindingsAndDisplay(InitStat
     }
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // The ContentSandboxHelper is currently the only one implementation of
   // GpuSandboxHelper and it has no dependency. Except on Linux where
   // VaapiWrapper checks the GL implementation to determine which display
@@ -996,7 +996,7 @@ bool GpuInit2::FinalizeGLInitialization(InitState& sta
     }
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Driver may create a compatibility profile context when collect graphics
   // information on Linux platform. Try to collect graphics information
   // based on core profile context after disabling platform extensions.
