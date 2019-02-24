--- base/trace_event/malloc_dump_provider.cc.orig	2019-01-30 02:17:39.000000000 +0100
+++ base/trace_event/malloc_dump_provider.cc	2019-01-31 22:27:52.377125000 +0100
@@ -17,6 +17,8 @@
 
 #if defined(OS_MACOSX)
 #include <malloc/malloc.h>
+#elif defined(OS_BSD)
+#include "stdlib.h"
 #else
 #include <malloc.h>
 #endif
@@ -132,6 +134,9 @@
   }
 #elif defined(OS_FUCHSIA)
 // TODO(fuchsia): Port, see https://crbug.com/706592.
+#elif defined(OS_BSD)
+  total_virtual_size = 0;
+  allocated_objects_size = 0;
 #else
   struct mallinfo info = mallinfo();
   DCHECK_GE(info.arena + info.hblkhd, info.uordblks);
