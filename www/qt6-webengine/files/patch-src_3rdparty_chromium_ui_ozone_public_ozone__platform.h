--- src/3rdparty/chromium/ui/ozone/public/ozone_platform.h.orig	2022-11-30 08:12:58 UTC
+++ src/3rdparty/chromium/ui/ozone/public/ozone_platform.h
@@ -144,7 +144,7 @@ class COMPONENT_EXPORT(OZONE) OzonePlatform {
     // back via gpu extra info.
     bool fetch_buffer_formats_for_gmb_on_gpu = false;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // TODO(crbug.com/1116701): add vaapi support for other Ozone platforms on
     // Linux. At the moment, VA-API Linux implementation supports only X11
     // backend. This implementation must be refactored to support Ozone
