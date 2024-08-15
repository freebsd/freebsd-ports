--- v8/src/execution/isolate.cc.orig	2024-08-01 05:47:53 UTC
+++ v8/src/execution/isolate.cc
@@ -157,6 +157,10 @@
 #include "src/execution/simulator-base.h"
 #endif
 
+#if defined(V8_OS_OPENBSD)
+#include <sys/mman.h>
+#endif
+
 extern "C" const uint8_t v8_Default_embedded_blob_code_[];
 extern "C" uint32_t v8_Default_embedded_blob_code_size_;
 extern "C" const uint8_t v8_Default_embedded_blob_data_[];
@@ -4540,6 +4544,13 @@ void Isolate::InitializeDefaultEmbeddedBlob() {
   uint32_t code_size = DefaultEmbeddedBlobCodeSize();
   const uint8_t* data = DefaultEmbeddedBlobData();
   uint32_t data_size = DefaultEmbeddedBlobDataSize();
+
+#if defined(V8_OS_OPENBSD) && !defined(V8_TARGET_ARCH_IA32)
+  if (code_size > 0) {
+    mprotect(reinterpret_cast<void *>(const_cast<uint8_t *>(code)),
+            code_size, PROT_READ | PROT_EXEC);
+  }
+#endif
 
   if (StickyEmbeddedBlobCode() != nullptr) {
     base::MutexGuard guard(current_embedded_blob_refcount_mutex_.Pointer());
