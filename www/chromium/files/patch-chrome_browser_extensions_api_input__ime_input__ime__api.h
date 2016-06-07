--- chrome/browser/extensions/api/input_ime/input_ime_api.h.orig	2016-05-11 19:02:14 UTC
+++ chrome/browser/extensions/api/input_ime/input_ime_api.h
@@ -27,7 +27,7 @@
 
 #if defined(OS_CHROMEOS)
 #include "chrome/browser/extensions/api/input_ime/input_ime_api_chromeos.h"
-#elif defined(OS_LINUX) || defined(OS_WIN)
+#elif defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
 #include "chrome/browser/extensions/api/input_ime/input_ime_api_nonchromeos.h"
 #endif  // defined(OS_CHROMEOS)
 
