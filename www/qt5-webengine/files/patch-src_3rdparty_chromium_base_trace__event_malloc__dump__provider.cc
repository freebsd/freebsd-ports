--- src/3rdparty/chromium/base/trace_event/malloc_dump_provider.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/base/trace_event/malloc_dump_provider.cc
@@ -18,7 +18,7 @@
 #if defined(OS_MACOSX)
 #include <malloc/malloc.h>
 #else
-#include <malloc.h>
+#include <stdlib.h>
 #endif
 #if defined(OS_WIN)
 #include <windows.h>
@@ -132,6 +132,9 @@ bool MallocDumpProvider::OnMemoryDump(const MemoryDump
   }
 #elif defined(OS_FUCHSIA)
 // TODO(fuchsia): Port, see https://crbug.com/706592.
+#elif defined(OS_BSD)
+  total_virtual_size = 0;
+  allocated_objects_size = 0;
 #else
   struct mallinfo info = mallinfo();
   DCHECK_GE(info.arena + info.hblkhd, info.uordblks);
