--- third_party/abseil-cpp/absl/base/config.h.orig	2026-09-25 15:26:43 UTC
+++ third_party/abseil-cpp/absl/base/config.h
@@ -377,7 +377,7 @@ static_assert(ABSL_INTERNAL_INLINE_NAMESPACE_STR[0] !=
 #ifdef ABSL_HAVE_SCHED_YIELD
 #error ABSL_HAVE_SCHED_YIELD cannot be directly set
 #elif defined(__linux__) || defined(__ros__) || defined(__native_client__) || \
-    defined(__VXWORKS__)
+    defined(__VXWORKS__) || defined(__OpenBSD__) || defined(__FreeBSD__)
 #define ABSL_HAVE_SCHED_YIELD 1
 #endif
 
@@ -392,7 +392,8 @@ static_assert(ABSL_INTERNAL_INLINE_NAMESPACE_STR[0] !=
 // platforms.
 #ifdef ABSL_HAVE_SEMAPHORE_H
 #error ABSL_HAVE_SEMAPHORE_H cannot be directly set
-#elif defined(__linux__) || defined(__ros__) || defined(__VXWORKS__)
+#elif defined(__linux__) || defined(__ros__) || defined(__VXWORKS__) || \
+    defined(__OpenBSD__) || defined(__FreeBSD__)
 #define ABSL_HAVE_SEMAPHORE_H 1
 #endif
 
