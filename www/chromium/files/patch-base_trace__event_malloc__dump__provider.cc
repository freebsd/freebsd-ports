--- base/trace_event/malloc_dump_provider.cc.orig	2021-12-14 11:44:55 UTC
+++ base/trace_event/malloc_dump_provider.cc
@@ -23,6 +23,8 @@
 
 #if defined(OS_APPLE)
 #include <malloc/malloc.h>
+#elif defined(OS_BSD)
+#include <stdlib.h>
 #else
 #include <malloc.h>
 #endif
@@ -217,6 +219,9 @@ bool MallocDumpProvider::OnMemoryDump(const MemoryDump
                      &allocated_objects_count);
 #elif defined(OS_FUCHSIA)
 // TODO(fuchsia): Port, see https://crbug.com/706592.
+#elif defined(OS_BSD)
+  total_virtual_size = 0;
+  allocated_objects_size = 0;
 #else
 #if defined(__GLIBC__) && defined(__GLIBC_PREREQ)
 #if __GLIBC_PREREQ(2, 33)
