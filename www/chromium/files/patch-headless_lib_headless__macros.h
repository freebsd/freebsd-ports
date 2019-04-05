--- headless/lib/headless_macros.h.orig	2019-03-11 22:00:59 UTC
+++ headless/lib/headless_macros.h
@@ -7,8 +7,8 @@
 
 #include "build/build_config.h"
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 #define HEADLESS_USE_BREAKPAD
-#endif  // defined(OS_POSIX) && !defined(OS_MACOSX)
+#endif  // defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 
 #endif  // HEADLESS_LIB_HEADLESS_MACROS_H_
