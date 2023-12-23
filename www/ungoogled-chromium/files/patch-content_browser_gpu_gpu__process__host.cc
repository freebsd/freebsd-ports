--- content/browser/gpu/gpu_process_host.cc.orig	2023-12-23 12:33:28 UTC
+++ content/browser/gpu/gpu_process_host.cc
@@ -254,6 +254,7 @@ static const char* const kSwitchNames[] = {
     switches::kEnableGpuRasterization,
     switches::kEnableSkiaGraphite,
     switches::kEnableLogging,
+    switches::kDisableUnveil,
     switches::kDoubleBufferCompositing,
     switches::kHeadless,
     switches::kLoggingLevel,
@@ -289,7 +290,7 @@ static const char* const kSwitchNames[] = {
     switches::kOzoneDumpFile,
     switches::kDisableBufferBWCompression,
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     switches::kX11Display,
     switches::kNoXshm,
 #endif
