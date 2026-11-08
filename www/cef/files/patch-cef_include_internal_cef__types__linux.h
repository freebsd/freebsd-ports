--- cef/include/internal/cef_types_linux.h.orig	2026-09-06 17:31:54 UTC
+++ cef/include/internal/cef_types_linux.h
@@ -35,7 +35,7 @@
 #include "include/base/cef_build.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 
 #include "include/internal/cef_export.h"
 #include "include/internal/cef_string.h"
