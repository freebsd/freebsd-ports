--- content/browser/gpu/gpu_process_host.cc.orig	2024-05-23 20:04:36 UTC
+++ content/browser/gpu/gpu_process_host.cc
@@ -265,6 +265,7 @@ static const char* const kSwitchNames[] = {
     switches::kEnableLowEndDeviceMode,
     switches::kDisableSkiaGraphite,
     switches::kDisableLowEndDeviceMode,
+    switches::kDisableUnveil,
     switches::kProfilingAtStart,
     switches::kProfilingFile,
     switches::kProfilingFlush,
@@ -292,7 +293,7 @@ static const char* const kSwitchNames[] = {
     switches::kDisableExplicitDmaFences,
     switches::kOzoneDumpFile,
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     switches::kX11Display,
     switches::kNoXshm,
 #endif
