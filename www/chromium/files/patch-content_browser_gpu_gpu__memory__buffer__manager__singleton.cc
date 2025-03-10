--- content/browser/gpu/gpu_memory_buffer_manager_singleton.cc.orig	2025-01-15 09:18:26 UTC
+++ content/browser/gpu/gpu_memory_buffer_manager_singleton.cc
@@ -46,7 +46,7 @@ scoped_refptr<base::SingleThreadTaskRunner> GetTaskRun
 #endif
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool IsGpuMemoryBufferNV12Supported() {
   static bool is_computed = false;
   static bool supported = false;
@@ -111,7 +111,7 @@ void GpuMemoryBufferManagerSingleton::RemoveObserver(
 }
 
 void GpuMemoryBufferManagerSingleton::OnGpuExtraInfoUpdate() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Dynamic check whether the NV12 format is supported as it may be
   // inconsistent between the system GBM (Generic Buffer Management) and
   // chromium miniGBM.
