--- base/allocator/partition_allocator/page_allocator_internals_posix.h.orig	2019-06-04 18:55:15 UTC
+++ base/allocator/partition_allocator/page_allocator_internals_posix.h
@@ -14,7 +14,7 @@
 #if defined(OS_MACOSX)
 #include <mach/mach.h>
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_BSD) || defined(OS_LINUX)
 #include <sys/resource.h>
 
 #include <algorithm>
