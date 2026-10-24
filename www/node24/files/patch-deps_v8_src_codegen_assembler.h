--- deps/v8/src/codegen/assembler.h.orig	2026-09-08 00:10:00 UTC
+++ deps/v8/src/codegen/assembler.h
@@ -383,9 +383,10 @@ class V8_EXPORT_PRIVATE AssemblerBase :
   int pc_offset() const { return static_cast<int>(pc_ - buffer_start_); }
 
   int pc_offset_for_safepoint() {
-#if defined(V8_TARGET_ARCH_MIPS64) || defined(V8_TARGET_ARCH_LOONG64)
-    // MIPS and LOONG need to use their own implementation to avoid trampoline's
-    // influence.
+#if defined(V8_TARGET_ARCH_MIPS64) || defined(V8_TARGET_ARCH_LOONG64) || \
+    defined(V8_TARGET_ARCH_PPC64)
+    // MIPS, LOONG and PPC64 need to use their own implementation to avoid
+    // trampoline's influence.
     UNREACHABLE();
 #else
     return pc_offset();
