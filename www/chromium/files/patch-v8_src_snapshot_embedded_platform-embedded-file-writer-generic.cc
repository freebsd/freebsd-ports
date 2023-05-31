--- v8/src/snapshot/embedded/platform-embedded-file-writer-generic.cc.orig	2023-05-31 08:12:17 UTC
+++ v8/src/snapshot/embedded/platform-embedded-file-writer-generic.cc
@@ -9,6 +9,10 @@
 
 #include "src/objects/instruction-stream.h"
 
+#if V8_OS_OPENBSD
+#include <sys/param.h>
+#endif
+
 namespace v8 {
 namespace internal {
 
@@ -35,6 +39,8 @@ const char* DirectiveAsString(DataDirective directive)
 void PlatformEmbeddedFileWriterGeneric::SectionText() {
   if (target_os_ == EmbeddedTargetOs::kChromeOS) {
     fprintf(fp_, ".section .text.hot.embedded\n");
+  } else if (target_os_ == EmbeddedTargetOs::kOpenBSD) {
+    fprintf(fp_, ".section .openbsd.mutable,\"a\"\n");
   } else {
     fprintf(fp_, ".section .text\n");
   }
@@ -66,6 +72,8 @@ void PlatformEmbeddedFileWriterGeneric::AlignToCodeAli
   // On these architectures and platforms, we remap the builtins, so need these
   // to be aligned on a page boundary.
   fprintf(fp_, ".balign 4096\n");
+#elif V8_OS_OPENBSD
+  fprintf(fp_, ".balign %d\n", PAGE_SIZE);
 #elif V8_TARGET_ARCH_X64
   // On x64 use 64-bytes code alignment to allow 64-bytes loop header alignment.
   static_assert(64 >= kCodeAlignment);
@@ -86,6 +94,8 @@ void PlatformEmbeddedFileWriterGeneric::AlignToPageSiz
     (V8_TARGET_ARCH_X64 || V8_TARGET_ARCH_ARM64)
   // Since the builtins are remapped, need to pad until the next page boundary.
   fprintf(fp_, ".balign 4096\n");
+#elif V8_OS_OPENBSD
+  fprintf(fp_, ".balign %d\n", PAGE_SIZE);
 #endif
 }
 
