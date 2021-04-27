--- third_party/pdfium/third_party/base/allocator/partition_allocator/page_allocator_internals_posix.h.orig	2021-04-20 19:05:14 UTC
+++ third_party/pdfium/third_party/base/allocator/partition_allocator/page_allocator_internals_posix.h
@@ -16,7 +16,7 @@
 #if defined(OS_ANDROID)
 #include <sys/prctl.h>
 #endif
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include <sys/resource.h>
 
 #include <algorithm>
