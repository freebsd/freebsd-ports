--- media/gpu/vaapi/vaapi_wrapper.cc.orig	2023-01-17 19:19:00 UTC
+++ media/gpu/vaapi/vaapi_wrapper.cc
@@ -740,7 +740,7 @@ VADisplayState::VADisplayState()
 bool VADisplayState::Initialize() {
   base::AutoLock auto_lock(va_lock_);
 
-#if BUILDFLAG(IS_OZONE) && BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_OZONE) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
   // TODO(crbug.com/1116701): add vaapi support for other Ozone platforms on
   // Linux. See comment in OzonePlatform::PlatformProperties::supports_vaapi
   // for more details. This will also require revisiting everything that's
