--- third_party/abseil-cpp/absl/debugging/internal/elf_mem_image.h.orig	2022-02-07 13:39:41 UTC
+++ third_party/abseil-cpp/absl/debugging/internal/elf_mem_image.h
@@ -32,7 +32,7 @@
 #endif
 
 #if defined(__ELF__) && !defined(__native_client__) && !defined(__asmjs__) && \
-    !defined(__wasm__)
+    !defined(__wasm__) && !defined(__OpenBSD__) && !defined(__FreeBSD__)
 #define ABSL_HAVE_ELF_MEM_IMAGE 1
 #endif
 
