--- content/browser/gpu/gpu_process_host.cc.orig	2026-06-05 13:45:06 UTC
+++ content/browser/gpu/gpu_process_host.cc
@@ -286,6 +286,7 @@ static const char* const kSwitchNames[] = {
     switches::kDisableSkiaGraphite,
     switches::kDisableSkiaGraphitePrecompilation,
     switches::kDisableLowEndDeviceMode,
+    switches::kDisableUnveil,
     switches::kProfilingAtStart,
     switches::kProfilingFile,
     switches::kProfilingFlush,
@@ -310,7 +311,7 @@ static const char* const kSwitchNames[] = {
     switches::kEnableNativeGpuMemoryBuffers,
     switches::kRenderNodeOverride,
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     switches::kX11Display,
     switches::kNoXshm,
 #endif
