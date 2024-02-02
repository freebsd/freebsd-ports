--- media/gpu/vaapi/vaapi_wrapper.cc.orig	2024-01-30 07:53:34 UTC
+++ media/gpu/vaapi/vaapi_wrapper.cc
@@ -71,7 +71,7 @@
 using media_gpu_vaapi::kModuleVa_prot;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/files/file_util.h"
 #include "base/strings/string_split.h"
 #endif
@@ -1514,7 +1514,7 @@ VADisplayStateHandle VADisplayStateSingleton::GetHandl
     return {};
   }
 
-#if BUILDFLAG(IS_OZONE) && BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_OZONE) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
   // TODO(crbug.com/1116701): add vaapi support for other Ozone platforms on
   // Linux. See comment in OzonePlatform::PlatformProperties::supports_vaapi
   // for more details. This will also require revisiting everything that's
