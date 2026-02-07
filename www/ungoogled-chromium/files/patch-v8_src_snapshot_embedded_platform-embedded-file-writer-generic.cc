--- v8/src/snapshot/embedded/platform-embedded-file-writer-generic.cc.orig	2026-01-16 13:40:34 UTC
+++ v8/src/snapshot/embedded/platform-embedded-file-writer-generic.cc
@@ -9,6 +9,10 @@
 
 #include "src/objects/instruction-stream.h"
 
+#if V8_OS_OPENBSD
+#include <sys/param.h>
+#endif
+
 namespace v8 {
 namespace internal {
 
@@ -35,6 +39,10 @@ const char* DirectiveAsString(DataDirective directive)
 void PlatformEmbeddedFileWriterGeneric::SectionText() {
   if (target_os_ == EmbeddedTargetOs::kChromeOS) {
     fprintf(fp_, ".section .text.hot.embedded\n");
+#if !defined(V8_TARGET_ARCH_IA32)
+  } else if (target_os_ == EmbeddedTargetOs::kOpenBSD) {
+    fprintf(fp_, ".section .openbsd.mutable,\"a\"\n");
+#endif
   } else {
     fprintf(fp_, ".section .text\n");
   }
@@ -75,6 +83,8 @@ void PlatformEmbeddedFileWriterGeneric::AlignToCodeAli
 #else
   fprintf(fp_, ".balign 4096\n");
 #endif
+#elif defined(V8_OS_OPENBSD) && !defined(V8_TARGET_ARCH_IA32)
+  fprintf(fp_, ".balign %d\n", PAGE_SIZE);
 #else
   fprintf(fp_, ".balign %d\n", static_cast<int>(kCodeAlignment));
 #endif
@@ -92,6 +102,8 @@ void PlatformEmbeddedFileWriterGeneric::AlignToPageSiz
 #else
   fprintf(fp_, ".balign 4096\n");
 #endif
+#elif defined(V8_OS_OPENBSD) && !defined(V8_TARGET_ARCH_IA32)
+  fprintf(fp_, ".balign %d\n", PAGE_SIZE);
 #endif
 }
 
