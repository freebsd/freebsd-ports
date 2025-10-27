--- content/browser/gpu/gpu_process_host.cc.orig	2025-10-21 16:57:35 UTC
+++ content/browser/gpu/gpu_process_host.cc
@@ -276,6 +276,7 @@ static const char* const kSwitchNames[] = {
     switches::kDisableSkiaGraphite,
     switches::kDisableSkiaGraphitePrecompilation,
     switches::kDisableLowEndDeviceMode,
+    switches::kDisableUnveil,
     switches::kProfilingAtStart,
     switches::kProfilingFile,
     switches::kProfilingFlush,
@@ -301,7 +302,7 @@ static const char* const kSwitchNames[] = {
     switches::kEnableNativeGpuMemoryBuffers,
     switches::kRenderNodeOverride,
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     switches::kX11Display,
     switches::kNoXshm,
 #endif
