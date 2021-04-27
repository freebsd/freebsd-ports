--- headless/lib/headless_macros.h.orig	2021-04-14 18:41:04 UTC
+++ headless/lib/headless_macros.h
@@ -7,8 +7,8 @@
 
 #include "build/build_config.h"
 
-#if defined(OS_POSIX) && !defined(OS_MAC)
+#if defined(OS_POSIX) && !defined(OS_MAC) && !defined(OS_BSD)
 #define HEADLESS_USE_BREAKPAD
-#endif  // defined(OS_POSIX) && !defined(OS_MAC)
+#endif  // defined(OS_POSIX) && !defined(OS_MAC) && !defined(OS_BSD)
 
 #endif  // HEADLESS_LIB_HEADLESS_MACROS_H_
