--- content/browser/gpu/gpu_process_host.cc.orig	2023-08-18 10:26:52 UTC
+++ content/browser/gpu/gpu_process_host.cc
@@ -253,6 +253,7 @@ static const char* const kSwitchNames[] = {
     switches::kEnableBackgroundThreadPool,
     switches::kEnableGpuRasterization,
     switches::kEnableLogging,
+    switches::kDisableUnveil,
     switches::kDoubleBufferCompositing,
     switches::kHeadless,
     switches::kLoggingLevel,
@@ -286,7 +287,7 @@ static const char* const kSwitchNames[] = {
     switches::kOzoneDumpFile,
     switches::kDisableBufferBWCompression,
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     switches::kX11Display,
     switches::kNoXshm,
 #endif
