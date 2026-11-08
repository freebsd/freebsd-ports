--- content/browser/gpu/gpu_process_host.cc.orig	2026-10-31 12:09:36 UTC
+++ content/browser/gpu/gpu_process_host.cc
@@ -297,6 +297,7 @@ static const char* const kSwitchNames[] = {
     switches::kDisableSkiaGraphite,
     switches::kDisableSkiaGraphitePrecompilation,
     switches::kDisableLowEndDeviceMode,
+    switches::kDisableUnveil,
     switches::kProfilingAtStart,
     switches::kProfilingFile,
     switches::kProfilingFlush,
@@ -321,7 +322,7 @@ static const char* const kSwitchNames[] = {
     switches::kEnableNativeGpuMemoryBuffers,
     switches::kRenderNodeOverride,
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     switches::kX11Display,
     switches::kNoXshm,
 #endif
