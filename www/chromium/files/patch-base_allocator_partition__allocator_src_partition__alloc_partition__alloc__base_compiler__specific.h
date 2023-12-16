--- base/allocator/partition_allocator/src/partition_alloc/partition_alloc_base/compiler_specific.h.orig	2023-12-10 06:10:27 UTC
+++ base/allocator/partition_allocator/src/partition_alloc/partition_alloc_base/compiler_specific.h
@@ -24,9 +24,9 @@
 // Annotate a function indicating it should not be inlined.
 // Use like:
 //   NOINLINE void DoStuff() { ... }
-#if defined(__clang__) && PA_HAS_ATTRIBUTE(noinline)
+#if defined(__clang__) && (__clang_major__ >= 15) && PA_HAS_ATTRIBUTE(noinline)
 #define PA_NOINLINE [[clang::noinline]]
-#elif defined(COMPILER_GCC) && PA_HAS_ATTRIBUTE(noinline)
+#elif (defined(COMPILER_GCC) || defined(__clang__)) && PA_HAS_ATTRIBUTE(noinline)
 #define PA_NOINLINE __attribute__((noinline))
 #elif defined(COMPILER_MSVC)
 #define PA_NOINLINE __declspec(noinline)
@@ -34,7 +34,7 @@
 #define PA_NOINLINE
 #endif
 
-#if defined(__clang__) && defined(NDEBUG) && PA_HAS_ATTRIBUTE(always_inline)
+#if defined(__clang__) && (__clang_major__ >= 15) && defined(NDEBUG) && PA_HAS_ATTRIBUTE(always_inline)
 #define PA_ALWAYS_INLINE [[clang::always_inline]] inline
 #elif defined(COMPILER_GCC) && defined(NDEBUG) && \
     PA_HAS_ATTRIBUTE(always_inline)
@@ -53,7 +53,7 @@
 // prevent code folding, see NO_CODE_FOLDING() in base/debug/alias.h.
 // Use like:
 //   void NOT_TAIL_CALLED FooBar();
-#if defined(__clang__) && PA_HAS_ATTRIBUTE(not_tail_called)
+#if defined(__clang__) && (__clang_major__ >= 15) && PA_HAS_ATTRIBUTE(not_tail_called)
 #define PA_NOT_TAIL_CALLED [[clang::not_tail_called]]
 #else
 #define PA_NOT_TAIL_CALLED
