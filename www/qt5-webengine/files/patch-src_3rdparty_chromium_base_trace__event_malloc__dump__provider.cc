--- src/3rdparty/chromium/base/trace_event/malloc_dump_provider.cc.orig	2017-01-26 00:49:07 UTC
+++ src/3rdparty/chromium/base/trace_event/malloc_dump_provider.cc
@@ -21,7 +21,7 @@
 #if defined(OS_MACOSX)
 #include <malloc/malloc.h>
 #else
-#include <malloc.h>
+#include <stdlib.h>
 #endif
 #if defined(OS_WIN)
 #include <windows.h>
