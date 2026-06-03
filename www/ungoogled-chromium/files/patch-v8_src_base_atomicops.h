--- v8/src/base/atomicops.h.orig	2025-12-06 13:30:52 UTC
+++ v8/src/base/atomicops.h
@@ -32,10 +32,10 @@ using Atomic64 = SbAtomic64;
 using Atomic8 = char;
 using Atomic16 = int16_t;
 using Atomic32 = int32_t;
-#if defined(V8_HOST_ARCH_64_BIT)
+#if defined(V8_HOST_ARCH_64_BIT) || defined(V8_OS_OPENBSD)
 // We need to be able to go between Atomic64 and AtomicWord implicitly.  This
 // means Atomic64 and AtomicWord should be the same type on 64-bit.
-#if defined(__ILP32__)
+#if defined(__ILP32__) && !defined(V8_OS_OPENBSD)
 using Atomic64 = int64_t;
 #else
 using Atomic64 = intptr_t;
@@ -59,7 +59,7 @@ inline void SeqCst_MemoryFence() {
 
 template <typename T>
 concept AtomicTypeForTrivialOperations =
-#if defined(V8_HOST_ARCH_64_BIT)
+#if defined(V8_HOST_ARCH_64_BIT) || defined(V8_OS_OPENBSD)
     std::is_same_v<T, Atomic64> ||
 #endif
     std::is_same_v<T, Atomic8> || std::is_same_v<T, Atomic16> ||
