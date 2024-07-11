--- content/browser/gpu/gpu_process_host.cc.orig	2024-06-22 08:49:42 UTC
+++ content/browser/gpu/gpu_process_host.cc
@@ -268,6 +268,7 @@ static const char* const kSwitchNames[] = {
     switches::kEnableLowEndDeviceMode,
     switches::kDisableSkiaGraphite,
     switches::kDisableLowEndDeviceMode,
+    switches::kDisableUnveil,
     switches::kProfilingAtStart,
     switches::kProfilingFile,
     switches::kProfilingFlush,
@@ -295,7 +296,7 @@ static const char* const kSwitchNames[] = {
     switches::kOzoneDumpFile,
     switches::kEnableNativeGpuMemoryBuffers,
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     switches::kX11Display,
     switches::kNoXshm,
 #endif
