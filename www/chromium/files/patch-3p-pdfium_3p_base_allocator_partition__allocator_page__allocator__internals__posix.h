--- third_party/pdfium/third_party/base/allocator/partition_allocator/page_allocator_internals_posix.h.orig	2021-10-08 06:29:18 UTC
+++ third_party/pdfium/third_party/base/allocator/partition_allocator/page_allocator_internals_posix.h
@@ -16,7 +16,7 @@
 #if defined(OS_ANDROID)
 #include <sys/prctl.h>
 #endif
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include <sys/resource.h>
 
 #include <algorithm>
