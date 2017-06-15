--- base/trace_event/malloc_dump_provider.cc.orig	2017-04-19 19:06:28 UTC
+++ base/trace_event/malloc_dump_provider.cc
@@ -21,7 +21,7 @@
 #if defined(OS_MACOSX)
 #include <malloc/malloc.h>
 #else
-#include <malloc.h>
+#include <stdlib.h>
 #endif
 #if defined(OS_WIN)
 #include <windows.h>
