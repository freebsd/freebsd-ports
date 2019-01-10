--- services/tracing/tracing_service.h.orig	2019-01-09 13:15:21.114712000 +0100
+++ services/tracing/tracing_service.h	2019-01-09 13:15:33.753522000 +0100
@@ -18,7 +18,7 @@
 #include "services/tracing/coordinator.h"
 
 #if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_MACOSX) || \
-    defined(OS_WIN)
+    defined(OS_WIN) || defined(OS_BSD)
 #define PERFETTO_SERVICE_AVAILABLE
 #endif
 
