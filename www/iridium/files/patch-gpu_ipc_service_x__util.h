--- gpu/ipc/service/x_util.h.orig	2022-03-28 18:11:04 UTC
+++ gpu/ipc/service/x_util.h
@@ -11,11 +11,11 @@
 #include "build/build_config.h"
 #include "gpu/ipc/service/gpu_config.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/ozone/buildflags.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #if BUILDFLAG(OZONE_PLATFORM_X11)
 
 namespace gpu {
