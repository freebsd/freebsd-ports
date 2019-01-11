--- components/services/font/font_service_app.cc.orig	2019-01-09 12:18:51.659675000 +0100
+++ components/services/font/font_service_app.cc	2019-01-09 12:19:08.146474000 +0100
@@ -21,7 +21,7 @@
 #include "components/services/font/ppapi_fontconfig_matching.h"  // nogncheck
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/test/fontconfig_util_linux.h"
 #endif
 
