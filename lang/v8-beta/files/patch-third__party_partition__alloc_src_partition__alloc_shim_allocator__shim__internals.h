--- third_party/partition_alloc/src/partition_alloc/shim/allocator_shim_internals.h.orig	2026-09-30 02:12:30 UTC
+++ third_party/partition_alloc/src/partition_alloc/shim/allocator_shim_internals.h
@@ -15,11 +15,15 @@
 #endif
 
 #ifndef __THROW   // Not a glibc system
-#ifdef _NOEXCEPT  // LLVM libc++ uses noexcept instead
+#if PA_BUILDFLAG(IS_FREEBSD)
+// FreeBSD stdlib.h declares malloc/free/etc. without exception specifications,
+// so __THROW must be empty to avoid a declaration mismatch.
+#define __THROW
+#elif defined(_NOEXCEPT)  // LLVM libc++ uses noexcept instead
 #define __THROW _NOEXCEPT
 #else
 #define __THROW
-#endif  // !_NOEXCEPT
+#endif  // IS_FREEBSD / _NOEXCEPT
 #endif
 
 // Shim layer symbols need to be ALWAYS exported, regardless of component build.
