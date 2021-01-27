--- base/allocator/partition_allocator/page_allocator_internals_posix.h.orig	2021-01-18 21:28:44 UTC
+++ base/allocator/partition_allocator/page_allocator_internals_posix.h
@@ -26,7 +26,7 @@
 #if defined(OS_ANDROID)
 #include <sys/prctl.h>
 #endif
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include <sys/resource.h>
 
 #include <algorithm>
