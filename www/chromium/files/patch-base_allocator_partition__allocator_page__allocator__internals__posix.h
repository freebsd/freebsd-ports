--- base/allocator/partition_allocator/page_allocator_internals_posix.h.orig	2020-11-13 06:36:34 UTC
+++ base/allocator/partition_allocator/page_allocator_internals_posix.h
@@ -24,7 +24,7 @@
 #if defined(OS_ANDROID)
 #include <sys/prctl.h>
 #endif
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include <sys/resource.h>
 
 #include <algorithm>
