--- media/gpu/vaapi/vaapi_wrapper.cc.orig	2023-09-17 07:59:53 UTC
+++ media/gpu/vaapi/vaapi_wrapper.cc
@@ -1610,7 +1610,7 @@ VADisplayStateHandle VADisplayStateSingleton::GetHandl
     return {};
   }
 
-#if BUILDFLAG(IS_OZONE) && BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_OZONE) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
   // TODO(crbug.com/1116701): add vaapi support for other Ozone platforms on
   // Linux. See comment in OzonePlatform::PlatformProperties::supports_vaapi
   // for more details. This will also require revisiting everything that's
@@ -2454,7 +2454,7 @@ scoped_refptr<VASurface> VaapiWrapper::CreateVASurface
     return nullptr;
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // TODO(crbug.com/1326754): enable use DRIME_PRIME_2 API on Linux with the
   // iHD driver.
   const bool use_drm_prime_2 = false;
