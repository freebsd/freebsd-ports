--- content/browser/gpu/gpu_process_host.cc.orig	2022-12-06 08:09:13 UTC
+++ content/browser/gpu/gpu_process_host.cc
@@ -255,6 +255,7 @@ static const char* const kSwitchNames[] = {
     switches::kEnableBackgroundThreadPool,
     switches::kEnableGpuRasterization,
     switches::kEnableLogging,
+    switches::kDisableUnveil,
     switches::kEnableDeJelly,
     switches::kDeJellyScreenWidth,
     switches::kDoubleBufferCompositing,
@@ -288,7 +289,7 @@ static const char* const kSwitchNames[] = {
     switches::kOzoneDumpFile,
     switches::kDisableBufferBWCompression,
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     switches::kX11Display,
     switches::kNoXshm,
 #endif
