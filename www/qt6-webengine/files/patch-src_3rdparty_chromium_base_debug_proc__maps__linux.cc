--- src/3rdparty/chromium/base/debug/proc_maps_linux.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/base/debug/proc_maps_linux.cc
@@ -13,7 +13,7 @@
 #include "base/strings/string_split.h"
 #include "build/build_config.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 #include <inttypes.h>
 #endif
 
