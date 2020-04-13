--- src/3rdparty/chromium/base/allocator/partition_allocator/page_allocator_internals_posix.h.orig	2019-11-27 21:12:25 UTC
+++ src/3rdparty/chromium/base/allocator/partition_allocator/page_allocator_internals_posix.h
@@ -16,7 +16,7 @@
 
 #include <mach/mach.h>
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_BSD) || defined(OS_LINUX)
 #include <sys/resource.h>
 
 #include <algorithm>
