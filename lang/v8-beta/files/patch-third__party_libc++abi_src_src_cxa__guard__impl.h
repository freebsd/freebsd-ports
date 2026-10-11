--- third_party/libc++abi/src/src/cxa_guard_impl.h.orig	2026-05-28 05:23:49 UTC
+++ third_party/libc++abi/src/src/cxa_guard_impl.h
@@ -156,12 +156,12 @@ class AtomicInt { (private)
 //                       PlatformGetThreadID
 //===----------------------------------------------------------------------===//
 
-#if defined(__APPLE__) && _LIBCPP_HAS_THREAD_API_PTHREAD
+#if defined(__APPLE__) && defined(_LIBCPP_HAS_THREAD_API_PTHREAD)
 uint32_t PlatformThreadID() {
   static_assert(sizeof(mach_port_t) == sizeof(uint32_t), "");
   return static_cast<uint32_t>(pthread_mach_thread_np(std::__libcpp_thread_get_current_id()));
 }
-#elif defined(SYS_gettid) && _LIBCPP_HAS_THREAD_API_PTHREAD
+#elif defined(SYS_gettid) && defined(_LIBCPP_HAS_THREAD_API_PTHREAD)
 uint32_t PlatformThreadID() {
   static_assert(sizeof(pid_t) == sizeof(uint32_t), "");
   return static_cast<uint32_t>(syscall(SYS_gettid));
