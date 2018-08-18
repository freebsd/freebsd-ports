--- third_party/blink/renderer/platform/wtf/atomics.h.orig	2018-07-19 20:13:40.615473000 +0200
+++ third_party/blink/renderer/platform/wtf/atomics.h	2018-07-19 20:13:55.934336000 +0200
@@ -176,7 +176,7 @@
 #if defined(THREAD_SANITIZER)
 // The definitions below assume an LP64 data model. This is fine because
 // TSan is only supported on x86_64 Linux.
-#if defined(ARCH_CPU_64_BITS) && defined(OS_LINUX)
+#if defined(ARCH_CPU_64_BITS) && defined(OS_LINUX) || defined(OS_BSD)
 ALWAYS_INLINE void ReleaseStore(volatile int* ptr, int value) {
   __tsan_atomic32_store(ptr, value, __tsan_memory_order_release);
 }
