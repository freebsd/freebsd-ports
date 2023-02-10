--- src/3rdparty/chromium/v8/src/compiler/backend/ia32/instruction-selector-ia32.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/v8/src/compiler/backend/ia32/instruction-selector-ia32.cc
@@ -3021,6 +3021,7 @@ void InstructionSelector::VisitI8x16Shuffle(Node* node
   Emit(opcode, 1, &dst, input_count, inputs, temp_count, temps);
 }
 
+#if V8_ENABLE_WEBASSEMBLY
 void InstructionSelector::VisitI8x16Swizzle(Node* node) {
   InstructionCode op = kIA32I8x16Swizzle;
 
@@ -3074,6 +3075,9 @@ void InstructionSelector::VisitF32x4Pmin(Node* node) {
 void InstructionSelector::VisitF32x4Pmin(Node* node) {
   VisitMinOrMax(this, node, kIA32Minps, true);
 }
+#else
+void InstructionSelector::VisitI8x16Swizzle(Node* node) { UNREACHABLE(); }
+#endif  // V8_ENABLE_WEBASSEMBLY
 
 void InstructionSelector::VisitF32x4Pmax(Node* node) {
   VisitMinOrMax(this, node, kIA32Maxps, true);
