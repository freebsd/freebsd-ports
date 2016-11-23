--- base/trace_event/malloc_dump_provider.cc.orig	2016-07-20 22:03:18.000000000 +0300
+++ base/trace_event/malloc_dump_provider.cc	2016-08-14 13:06:10.819247000 +0300
@@ -20,7 +20,7 @@
 #if defined(OS_MACOSX)
 #include <malloc/malloc.h>
 #else
-#include <malloc.h>
+#include <stdlib.h>
 #endif

 namespace base {
