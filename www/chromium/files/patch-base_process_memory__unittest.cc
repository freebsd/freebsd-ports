--- base/process/memory_unittest.cc.orig	2021-07-19 18:45:05 UTC
+++ base/process/memory_unittest.cc
@@ -37,6 +37,8 @@
 #if defined(OS_LINUX) || defined(OS_CHROMEOS)
 #include <malloc.h>
 #include "base/test/malloc_wrapper.h"
+#elif defined(OS_BSD)
+#include "base/test/malloc_wrapper.h"
 #endif
 #if defined(OS_ANDROID)
 #include "base/android/build_info.h"
@@ -112,9 +114,9 @@ TEST(MemoryTest, AllocatorShimWorking) {
 #endif
 }
 
-// OpenBSD does not support these tests. Don't test these on ASan/TSan/MSan
+// BSD does not support these tests. Don't test these on ASan/TSan/MSan
 // configurations: only test the real allocator.
-#if !defined(OS_OPENBSD) && BUILDFLAG(USE_ALLOCATOR_SHIM) && \
+#if !defined(OS_BSD) && BUILDFLAG(USE_ALLOCATOR_SHIM) && \
     !defined(MEMORY_TOOL_REPLACES_ALLOCATOR)
 
 namespace {
@@ -336,7 +338,7 @@ TEST_F(OutOfMemoryDeathTest, SecurityAlignedRealloc) {
 #endif  // defined(OS_WIN)
 #endif  // !defined(OS_MAC) && !defined(OS_ANDROID)
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 TEST_F(OutOfMemoryDeathTest, Valloc) {
   ASSERT_OOM_DEATH({
@@ -382,7 +384,7 @@ TEST_F(OutOfMemoryDeathTest, ViaSharedLibraries) {
     value_ = MallocWrapper(test_size_);
   });
 }
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 // Android doesn't implement posix_memalign().
 #if defined(OS_POSIX) && !defined(OS_ANDROID)
@@ -533,7 +535,7 @@ TEST_F(OutOfMemoryTest, TerminateBecauseOutOfMemoryRep
 #endif  // OS_WIN
 
 #if defined(ARCH_CPU_32_BITS) && \
-    (defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS))
+    (defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD))
 
 void TestAllocationsReleaseReservation(void* (*alloc_fn)(size_t),
                                        void (*free_fn)(void*)) {
@@ -591,7 +593,7 @@ TEST_F(OutOfMemoryHandledTest, NewReleasesReservation)
       [](size_t size) { return static_cast<void*>(new char[size]); },
       [](void* ptr) { delete[] static_cast<char*>(ptr); });
 }
-#endif  // defined(ARCH_CPU_32_BITS) && (defined(OS_WIN) || defined(OS_LINUX) ||
+#endif  // defined(ARCH_CPU_32_BITS) && (defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS))
 
 // See the comment in |UncheckedMalloc()|, it behaves as malloc() in these
@@ -653,5 +655,5 @@ TEST_F(OutOfMemoryHandledTest, UncheckedCalloc) {
 
 #endif  // BUILDFLAG(USE_PARTITION_ALLOC_AS_MALLOC) || defined(OS_ANDROID)
 
-#endif  // !defined(OS_OPENBSD) && BUILDFLAG(USE_ALLOCATOR_SHIM) &&
+#endif  // !defined(OS_BSD) && BUILDFLAG(USE_ALLOCATOR_SHIM) &&
         // !defined(MEMORY_TOOL_REPLACES_ALLOCATOR)
