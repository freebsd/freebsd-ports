--- components/services/font/font_service_app.cc.orig	2019-03-11 22:00:57 UTC
+++ components/services/font/font_service_app.cc
@@ -20,7 +20,7 @@
 #include "components/services/font/ppapi_fontconfig_matching.h"  // nogncheck
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/test/fontconfig_util_linux.h"
 #endif
 
