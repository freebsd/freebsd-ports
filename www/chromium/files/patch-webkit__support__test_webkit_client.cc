--- webkit/support/test_webkit_client.cc.orig	2011-02-03 10:01:07.000000000 +0100
+++ webkit/support/test_webkit_client.cc	2011-02-05 00:03:38.000000000 +0100
@@ -54,7 +54,7 @@
 #if defined(OS_WIN)
 #include "third_party/WebKit/Source/WebKit/chromium/public/win/WebThemeEngine.h"
 #include "webkit/tools/test_shell/test_shell_webthemeengine.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_OPENBSD) || defined(OS_FREEBSD)
 #include "third_party/WebKit/Source/WebKit/chromium/public/linux/WebThemeEngine.h"
 #elif defined(OS_MACOSX)
 #include "base/mac/mac_util.h"
