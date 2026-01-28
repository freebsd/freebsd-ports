--- media/gpu/vaapi/vaapi_wrapper.cc.orig	2026-01-16 13:40:34 UTC
+++ media/gpu/vaapi/vaapi_wrapper.cc
@@ -84,7 +84,7 @@
 using media_gpu_vaapi::kModuleVa_prot;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/strings/string_split.h"
 #endif
 
