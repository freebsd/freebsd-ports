--- src/3rdparty/chromium/media/gpu/vaapi/vaapi_wrapper.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/media/gpu/vaapi/vaapi_wrapper.cc
@@ -582,7 +582,7 @@ bool VADisplayState::Initialize() {
 bool VADisplayState::Initialize() {
   base::AutoLock auto_lock(va_lock_);
 
-#if defined(USE_OZONE) && BUILDFLAG(IS_LINUX)
+#if defined(USE_OZONE) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
   // TODO(crbug.com/1116701): add vaapi support for other Ozone platforms on
   // Linux. See comment in OzonePlatform::PlatformProperties::supports_vaapi
   // for more details. This will also require revisiting everything that's
