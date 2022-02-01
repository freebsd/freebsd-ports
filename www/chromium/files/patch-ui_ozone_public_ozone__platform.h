--- ui/ozone/public/ozone_platform.h.orig	2021-12-31 00:58:32 UTC
+++ ui/ozone/public/ozone_platform.h
@@ -156,7 +156,7 @@ class COMPONENT_EXPORT(OZONE) OzonePlatform {
     // back via gpu extra info.
     bool fetch_buffer_formats_for_gmb_on_gpu = false;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     // TODO(crbug.com/1116701): add vaapi support for other Ozone platforms on
     // Linux. At the moment, VA-API Linux implementation supports only X11
     // backend. This implementation must be refactored to support Ozone
