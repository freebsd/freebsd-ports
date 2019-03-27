--- src/3rdparty/chromium/headless/lib/headless_macros.h.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/headless/lib/headless_macros.h
@@ -7,8 +7,8 @@
 
 #include "build/build_config.h"
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 #define HEADLESS_USE_BREAKPAD
-#endif  // defined(OS_POSIX) && !defined(OS_MACOSX)
+#endif  // defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 
 #endif  // HEADLESS_LIB_HEADLESS_MACROS_H_
