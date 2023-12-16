--- src/3rdparty/chromium/third_party/abseil-cpp/absl/debugging/internal/elf_mem_image.h.orig	2022-08-31 12:19:35 UTC
+++ src/3rdparty/chromium/third_party/abseil-cpp/absl/debugging/internal/elf_mem_image.h
@@ -33,7 +33,7 @@
 
 #if defined(__ELF__) && !defined(__OpenBSD__) && !defined(__QNX__) && \
     !defined(__native_client__) && !defined(__asmjs__) &&             \
-    !defined(__wasm__) && !defined(__HAIKU__)
+    !defined(__wasm__) && !defined(__HAIKU__) && !defined(__FreeBSD__)
 #define ABSL_HAVE_ELF_MEM_IMAGE 1
 #endif
 
