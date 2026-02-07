--- src/3rdparty/chromium/base/allocator/partition_allocator/page_allocator_internals_posix.h.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/base/allocator/partition_allocator/page_allocator_internals_posix.h
@@ -24,7 +24,7 @@
 #if defined(OS_ANDROID)
 #include <sys/prctl.h>
 #endif
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include <sys/resource.h>
 
 #include <algorithm>
