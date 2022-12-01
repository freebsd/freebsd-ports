--- base/profiler/stack_base_address_posix.cc.orig	2022-12-01 10:35:46 UTC
+++ base/profiler/stack_base_address_posix.cc
@@ -15,6 +15,10 @@
 #include "base/files/scoped_file.h"
 #endif
 
+#if BUILDFLAG(IS_BSD)
+#include <pthread_np.h>
+#endif
+
 #if BUILDFLAG(IS_CHROMEOS)
 extern "C" void* __libc_stack_end;
 #endif
@@ -42,15 +46,30 @@ absl::optional<uintptr_t> GetAndroidMainThreadStackBas
 #endif
 
 uintptr_t GetThreadStackBaseAddressImpl(pthread_t pthread_id) {
+#if BUILDFLAG(IS_OPENBSD)
+  stack_t ss;
+  void *address;
+  size_t size;
+  if (pthread_stackseg_np(pthread_id, &ss) != 0)
+    return 0;
+  size = ss.ss_size;
+  address = (void*)((size_t) ss.ss_sp - ss.ss_size);
+#else
   pthread_attr_t attr;
+#if BUILDFLAG(IS_FREEBSD)
+  pthread_attr_init(&attr);
+  pthread_attr_get_np(pthread_id, &attr);
+#else
   // This will crash on ChromeOS & Linux if we are in the sandbox and pthread_id
   // refers to a different thread, due to the use of sched_getaffinity().
   pthread_getattr_np(pthread_id, &attr);
   // See crbug.com/617730 for limitations of this approach on Linux.
+#endif
   void* address;
   size_t size;
   pthread_attr_getstack(&attr, &address, &size);
   pthread_attr_destroy(&attr);
+#endif
   const uintptr_t base_address = reinterpret_cast<uintptr_t>(address) + size;
   return base_address;
 }
