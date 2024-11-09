--- content/browser/gpu/gpu_process_host.cc.orig	2024-11-04 08:56:03 UTC
+++ content/browser/gpu/gpu_process_host.cc
@@ -275,6 +275,7 @@ static const char* const kSwitchNames[] = {
     switches::kEnableLowEndDeviceMode,
     switches::kDisableSkiaGraphite,
     switches::kDisableLowEndDeviceMode,
+    switches::kDisableUnveil,
     switches::kProfilingAtStart,
     switches::kProfilingFile,
     switches::kProfilingFlush,
@@ -302,7 +303,7 @@ static const char* const kSwitchNames[] = {
     switches::kOzoneDumpFile,
     switches::kEnableNativeGpuMemoryBuffers,
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     switches::kX11Display,
     switches::kNoXshm,
 #endif
