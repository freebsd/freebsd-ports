--- v8/src/baseline/x64/baseline-assembler-x64-inl.h.orig	2023-11-22 14:00:11 UTC
+++ v8/src/baseline/x64/baseline-assembler-x64-inl.h
@@ -76,9 +76,7 @@ MemOperand BaselineAssembler::FeedbackCellOperand() {
 
 void BaselineAssembler::Bind(Label* label) { __ bind(label); }
 
-void BaselineAssembler::JumpTarget() {
-  // NOP on x64.
-}
+void BaselineAssembler::JumpTarget() { __ endbr64(); }
 
 void BaselineAssembler::Jump(Label* target, Label::Distance distance) {
   __ jmp(target, distance);
