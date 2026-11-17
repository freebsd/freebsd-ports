--- src/content/browser/gpu/gpu_process_host.cc.orig	2026-10-18 18:43:23 UTC
+++ src/content/browser/gpu/gpu_process_host.cc
@@ -296,6 +296,7 @@ static const char* const kSwitchNames[]
     switches::kDisableSkiaGraphite,
     switches::kDisableSkiaGraphitePrecompilation,
     switches::kDisableLowEndDeviceMode,
+    switches::kDisableUnveil,
     switches::kProfilingAtStart,
     switches::kProfilingFile,
     switches::kProfilingFlush,
@@ -320,7 +321,7 @@ static const char* const kSwitchNames[]
     switches::kEnableNativeGpuMemoryBuffers,
     switches::kRenderNodeOverride,
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     switches::kX11Display,
     switches::kNoXshm,
 #endif
