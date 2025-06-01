--- media/gpu/vaapi/vaapi_wrapper.cc.orig	2025-05-31 17:16:41 UTC
+++ media/gpu/vaapi/vaapi_wrapper.cc
@@ -82,7 +82,7 @@
 using media_gpu_vaapi::kModuleVa_prot;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/files/file_util.h"
 #include "base/strings/string_split.h"
 #endif
