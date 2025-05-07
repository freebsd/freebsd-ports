--- media/gpu/vaapi/vaapi_wrapper.cc.orig	2025-05-07 06:48:23 UTC
+++ media/gpu/vaapi/vaapi_wrapper.cc
@@ -81,7 +81,7 @@
 using media_gpu_vaapi::kModuleVa_prot;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/files/file_util.h"
 #include "base/strings/string_split.h"
 #endif
