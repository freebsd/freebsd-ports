--- src/3rdparty/chromium/media/gpu/vaapi/vaapi_wrapper.cc.orig	2025-08-07 06:57:29 UTC
+++ src/3rdparty/chromium/media/gpu/vaapi/vaapi_wrapper.cc
@@ -83,7 +83,7 @@
 using media_gpu_vaapi::kModuleVa_prot;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/files/file_util.h"
 #include "base/strings/string_split.h"
 #endif
