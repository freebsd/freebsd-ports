--- src/libtriton/includes/triton/tritonTypes.hpp.orig	2026-08-12 07:47:18 UTC
+++ src/libtriton/includes/triton/tritonTypes.hpp
@@ -105,15 +105,13 @@ namespace triton {
     //! unsigned MAX_INT 32 or 64 bits according to the CPU.
     typedef std::size_t usize;
 
-    #if defined(__x86_64__) || defined(_M_X64)  || defined(__aarch64__)
+    #if UINTPTR_MAX == UINT64_MAX
     //! unsigned long long if the arch is 64-bits.
     typedef unsigned long long __uint;
 
     //! signed long long if the arch is 64-bits.
     typedef signed long long __sint;
-    #endif
-
-    #if defined(__i386) || defined(_M_IX86)
+    #else
     //! unsigned int if the arch is 32-bits.
     typedef unsigned int __uint;
 
