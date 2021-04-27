--- base/allocator/partition_allocator/page_allocator_internals_posix.h.orig	2021-04-14 18:40:48 UTC
+++ base/allocator/partition_allocator/page_allocator_internals_posix.h
@@ -28,12 +28,16 @@
 #if defined(OS_ANDROID)
 #include <sys/prctl.h>
 #endif
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include <sys/resource.h>
 
 #include <algorithm>
 #endif
 
+#if defined(OS_FREEBSD)
+#include <fcntl.h>
+#endif
+
 #include "base/allocator/partition_allocator/page_allocator.h"
 
 #ifndef MAP_ANONYMOUS
@@ -153,12 +157,19 @@ void* SystemAllocPagesInternal(void* hint,
   PA_DCHECK(PageTag::kFirst <= page_tag);
   PA_DCHECK(PageTag::kLast >= page_tag);
   int fd = VM_MAKE_TAG(static_cast<int>(page_tag));
+#elif defined(OS_FREEBSD)
+  int fd = HANDLE_EINTR(open("/dev/zero", O_RDWR | O_CLOEXEC));
+  PA_PCHECK(fd != -1);
 #else
   int fd = -1;
 #endif
 
   int access_flag = GetAccessFlags(accessibility);
+#if defined(OS_FREEBSD)
+  int map_flags = MAP_PRIVATE;
+#else
   int map_flags = MAP_ANONYMOUS | MAP_PRIVATE;
+#endif
 
 #if defined(OS_APPLE)
   // On macOS 10.14 and higher, executables that are code signed with the
@@ -185,6 +196,8 @@ void* SystemAllocPagesInternal(void* hint,
     prctl(PR_SET_VMA, PR_SET_VMA_ANON_NAME, ret, length,
           PageTagToName(page_tag));
   }
+#elif defined(OS_FREEBSD)
+  HANDLE_EINTR(close(fd));
 #endif
 
   return ret;
@@ -317,6 +330,8 @@ void DiscardSystemPagesInternal(void* address, size_t 
     ret = madvise(address, length, MADV_DONTNEED);
   }
   PA_PCHECK(ret == 0);
+#elif defined(OS_FREEBSD)
+  PA_PCHECK(0 == madvise(address, length, MADV_FREE));
 #else
   // We have experimented with other flags, but with suboptimal results.
   //
