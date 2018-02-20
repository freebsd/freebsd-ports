--- headless/lib/headless_macros.h.orig	2017-12-15 02:04:19.000000000 +0100
+++ headless/lib/headless_macros.h	2017-12-24 16:44:30.147915000 +0100
@@ -7,8 +7,8 @@
 
 #include "build/build_config.h"
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_FUCHSIA)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_FUCHSIA) && !defined(OS_BSD)
 #define HEADLESS_USE_BREAKPAD
-#endif  // defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_FUCHSIA)
+#endif  // defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_FUCHSIA) && !defined(OS_BSD)
 
 #endif  // HEADLESS_LIB_HEADLESS_MACROS_H_
