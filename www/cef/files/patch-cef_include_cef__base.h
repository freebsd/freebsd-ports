--- cef/include/cef_base.h.orig	2026-09-06 17:31:54 UTC
+++ cef/include/cef_base.h
@@ -46,7 +46,7 @@
 #include "include/internal/cef_win.h"
 #elif defined(OS_MAC)
 #include "include/internal/cef_mac.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "include/internal/cef_linux.h"
 #endif
 
