--- third_party/abseil-cpp/absl/debugging/internal/elf_mem_image.h.orig	2021-12-31 00:57:39 UTC
+++ third_party/abseil-cpp/absl/debugging/internal/elf_mem_image.h
@@ -38,7 +38,14 @@
 
 #ifdef ABSL_HAVE_ELF_MEM_IMAGE
 
+#if defined(__FreeBSD__)
+#include <elf.h>
+#ifndef ElfW
+#define ElfW(x) __ElfN(x)
+#endif
+#else
 #include <link.h>  // for ElfW
+#endif
 
 #if defined(__FreeBSD__) && !defined(ElfW)
 #define ElfW(x) __ElfN(x)
