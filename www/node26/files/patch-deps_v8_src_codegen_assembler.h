--- deps/v8/src/codegen/assembler.h.orig	2026-09-21 21:15:56 UTC
+++ deps/v8/src/codegen/assembler.h
@@ -389,11 +389,12 @@ class V8_EXPORT_PRIVATE AssemblerBase :
 
   void skip_bytes(int num_bytes) { pc_ += num_bytes; }
 
-// MIPS, LOONG, and RISC-V need to use their own implementations to avoid the
-// influence of branch trampolines. They provide their implementations in the
-// architecture-specific assembler subclasses.
-#if !defined(V8_TARGET_ARCH_MIPS64) && !defined(V8_TARGET_ARCH_LOONG64) && \
-    !defined(V8_TARGET_ARCH_RISCV32) && !defined(V8_TARGET_ARCH_RISCV64)
+// MIPS, LOONG, RISC-V, and PPC64 need to use their own implementations to avoid
+// the influence of branch trampolines. They provide their implementations in
+// the architecture-specific assembler subclasses.
+#if !defined(V8_TARGET_ARCH_MIPS64) && !defined(V8_TARGET_ARCH_LOONG64) &&  \
+    !defined(V8_TARGET_ARCH_RISCV32) && !defined(V8_TARGET_ARCH_RISCV64) && \
+    !defined(V8_TARGET_ARCH_PPC64)
   int pc_offset_for_safepoint() const { return pc_offset(); }
 #endif
 
