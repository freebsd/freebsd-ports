--- src/3rdparty/chromium/components/services/font/font_service_app.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/components/services/font/font_service_app.cc
@@ -20,7 +20,7 @@
 #include "components/services/font/ppapi_fontconfig_matching.h"  // nogncheck
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/test/fontconfig_util_linux.h"
 #endif
 
