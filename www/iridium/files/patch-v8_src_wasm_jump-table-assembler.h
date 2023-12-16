--- v8/src/wasm/jump-table-assembler.h.orig	2023-11-22 14:00:11 UTC
+++ v8/src/wasm/jump-table-assembler.h
@@ -174,9 +174,10 @@ class V8_EXPORT_PRIVATE JumpTableAssembler : public Ma
 // boundaries. The jump table line size has been chosen to satisfy this.
 #if V8_TARGET_ARCH_X64
   static constexpr int kJumpTableLineSize = 64;
-  static constexpr int kJumpTableSlotSize = 5;
-  static constexpr int kFarJumpTableSlotSize = 16;
-  static constexpr int kLazyCompileTableSlotSize = 10;
+  static constexpr int kJumpTableSlotSize = 5 + 4;
+  static constexpr int kFarJumpTableSlotOffset = 2 * kSystemPointerSize;
+  static constexpr int kFarJumpTableSlotSize = 16 + 8;
+  static constexpr int kLazyCompileTableSlotSize = 10 + 4;
 #elif V8_TARGET_ARCH_IA32
   static constexpr int kJumpTableLineSize = 64;
   static constexpr int kJumpTableSlotSize = 5;
