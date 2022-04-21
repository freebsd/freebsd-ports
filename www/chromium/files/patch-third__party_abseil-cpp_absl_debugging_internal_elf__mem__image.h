--- third_party/abseil-cpp/absl/debugging/internal/elf_mem_image.h.orig	2022-04-21 18:48:31 UTC
+++ third_party/abseil-cpp/absl/debugging/internal/elf_mem_image.h
@@ -31,7 +31,7 @@
 #error ABSL_HAVE_ELF_MEM_IMAGE cannot be directly set
 #endif
 
-#if defined(__ELF__) && !defined(__OpenBSD__) && \
+#if defined(__ELF__) && !defined(__OpenBSD__) && !defined(__FreeBSD__) && \
     !defined(__native_client__) && !defined(__asmjs__) && !defined(__wasm__)
 #define ABSL_HAVE_ELF_MEM_IMAGE 1
 #endif
