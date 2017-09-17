--- third_party/WebKit/Source/platform/wtf/Atomics.h.orig	2017-09-05 21:05:41.000000000 +0200
+++ third_party/WebKit/Source/platform/wtf/Atomics.h	2017-09-06 22:14:43.075913000 +0200
@@ -176,7 +176,7 @@
 #if defined(THREAD_SANITIZER)
 // The definitions below assume an LP64 data model. This is fine because
 // TSan is only supported on x86_64 Linux.
-#if defined(ARCH_CPU_64_BITS) && defined(OS_LINUX)
+#if defined(ARCH_CPU_64_BITS) && (defined(OS_LINUX) || defined(OS_BSD))
 ALWAYS_INLINE void ReleaseStore(volatile int* ptr, int value) {
   __tsan_atomic32_store(ptr, value, __tsan_memory_order_release);
 }
