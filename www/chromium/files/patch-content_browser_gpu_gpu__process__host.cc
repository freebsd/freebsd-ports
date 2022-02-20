--- content/browser/gpu/gpu_process_host.cc.orig	2022-02-07 13:39:41 UTC
+++ content/browser/gpu/gpu_process_host.cc
@@ -101,7 +101,7 @@
 #include "ui/ozone/public/ozone_switches.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
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
@@ -295,7 +296,7 @@ static const char* const kSwitchNames[] = {
     switches::kOzoneDumpFile,
     switches::kDisableBufferBWCompression,
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     switches::kX11Display,
     switches::kNoXshm,
 #endif
