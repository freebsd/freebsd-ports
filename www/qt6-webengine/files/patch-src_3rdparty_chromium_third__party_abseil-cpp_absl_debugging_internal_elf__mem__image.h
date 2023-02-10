--- src/3rdparty/chromium/third_party/abseil-cpp/absl/debugging/internal/elf_mem_image.h.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/third_party/abseil-cpp/absl/debugging/internal/elf_mem_image.h
@@ -32,7 +32,8 @@
 #endif
 
 #if defined(__ELF__) && !defined(__OpenBSD__) && !defined(__QNX__) &&  \
-    !defined(__native_client__) && !defined(__asmjs__) && !defined(__wasm__)
+    !defined(__native_client__) && !defined(__asmjs__) && !defined(__wasm__) && \
+    !defined(__FreeBSD__)
 #define ABSL_HAVE_ELF_MEM_IMAGE 1
 #endif
 
