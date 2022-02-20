--- gpu/ipc/service/x_util.h.orig	2022-02-07 13:39:41 UTC
+++ gpu/ipc/service/x_util.h
@@ -11,11 +11,11 @@
 #include "build/build_config.h"
 #include "gpu/ipc/service/gpu_config.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "ui/ozone/buildflags.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #if BUILDFLAG(OZONE_PLATFORM_X11)
 
 namespace gpu {
