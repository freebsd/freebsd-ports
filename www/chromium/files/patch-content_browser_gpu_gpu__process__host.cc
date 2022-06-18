--- content/browser/gpu/gpu_process_host.cc.orig	2022-06-17 14:20:10 UTC
+++ content/browser/gpu/gpu_process_host.cc
@@ -102,7 +102,7 @@
 #include "ui/ozone/public/ozone_switches.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/gfx/switches.h"
 #endif
 
@@ -254,6 +254,7 @@ static const char* const kSwitchNames[] = {
     switches::kEnableBackgroundThreadPool,
     switches::kEnableGpuRasterization,
     switches::kEnableLogging,
+    switches::kDisableUnveil,
     switches::kEnableDeJelly,
     switches::kDeJellyScreenWidth,
     switches::kDoubleBufferCompositing,
@@ -290,7 +291,7 @@ static const char* const kSwitchNames[] = {
     switches::kOzoneDumpFile,
     switches::kDisableBufferBWCompression,
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     switches::kX11Display,
     switches::kNoXshm,
 #endif
