--- third_party/abseil-cpp/absl/debugging/internal/elf_mem_image.h.orig	2024-08-26 14:40:28 UTC
+++ third_party/abseil-cpp/absl/debugging/internal/elf_mem_image.h
@@ -35,7 +35,7 @@
 #if defined(__ELF__) && !defined(__OpenBSD__) && !defined(__QNX__) && \
     !defined(__native_client__) && !defined(__asmjs__) &&             \
     !defined(__wasm__) && !defined(__HAIKU__) && !defined(__sun) &&   \
-    !defined(__VXWORKS__) && !defined(__hexagon__)
+    !defined(__VXWORKS__) && !defined(__hexagon__) && !defined(__FreeBSD__)
 #define ABSL_HAVE_ELF_MEM_IMAGE 1
 #endif
 
