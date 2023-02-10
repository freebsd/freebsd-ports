--- src/3rdparty/chromium/content/browser/gpu/gpu_process_host.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/content/browser/gpu/gpu_process_host.cc
@@ -100,7 +100,7 @@
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
     switches::kDocumentTransitionSlowdownFactor,
@@ -291,7 +292,7 @@ static const char* const kSwitchNames[] = {
     switches::kOzoneDumpFile,
     switches::kDisableBufferBWCompression,
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     switches::kX11Display,
     switches::kNoXshm,
 #endif
