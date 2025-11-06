--- content/browser/gpu/gpu_process_host.cc.orig	2025-11-06 10:11:34 UTC
+++ content/browser/gpu/gpu_process_host.cc
@@ -280,6 +280,7 @@ static const char* const kSwitchNames[] = {
     switches::kDisableSkiaGraphite,
     switches::kDisableSkiaGraphitePrecompilation,
     switches::kDisableLowEndDeviceMode,
+    switches::kDisableUnveil,
     switches::kProfilingAtStart,
     switches::kProfilingFile,
     switches::kProfilingFlush,
@@ -305,7 +306,7 @@ static const char* const kSwitchNames[] = {
     switches::kEnableNativeGpuMemoryBuffers,
     switches::kRenderNodeOverride,
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     switches::kX11Display,
     switches::kNoXshm,
 #endif
