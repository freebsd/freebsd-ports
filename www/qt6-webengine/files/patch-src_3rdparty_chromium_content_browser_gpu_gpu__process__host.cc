--- src/3rdparty/chromium/content/browser/gpu/gpu_process_host.cc.orig	2024-07-03 01:14:49 UTC
+++ src/3rdparty/chromium/content/browser/gpu/gpu_process_host.cc
@@ -258,6 +258,7 @@ static const char* const kSwitchNames[] = {
     switches::kEnableGpuRasterization,
     switches::kEnableSkiaGraphite,
     switches::kEnableLogging,
+    switches::kDisableUnveil,
     switches::kDoubleBufferCompositing,
     switches::kHeadless,
     switches::kLoggingLevel,
@@ -292,7 +293,7 @@ static const char* const kSwitchNames[] = {
     switches::kDisableExplicitDmaFences,
     switches::kOzoneDumpFile,
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     switches::kX11Display,
     switches::kNoXshm,
 #endif
