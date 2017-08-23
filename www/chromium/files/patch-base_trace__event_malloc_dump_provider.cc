--- base/trace_event/malloc_dump_provider.cc.orig	2017-08-02 18:33:27.773657000 +0200
+++ base/trace_event/malloc_dump_provider.cc	2017-08-02 18:34:48.019053000 +0200
@@ -21,6 +21,8 @@
 
 #if defined(OS_MACOSX)
 #include <malloc/malloc.h>
+#elif defined(OS_BSD)
+#include "stdlib.h"
 #else
 #include <malloc.h>
 #endif
@@ -243,6 +245,9 @@
   allocated_objects_count = main_heap_info.block_count;
 #elif defined(OS_FUCHSIA)
 // TODO(fuchsia): Port, see https://crbug.com/706592.
+#elif defined(OS_BSD)
+  total_virtual_size = 0;
+  allocated_objects_size = 0;
 #else
   struct mallinfo info = mallinfo();
   DCHECK_GE(info.arena + info.hblkhd, info.uordblks);
