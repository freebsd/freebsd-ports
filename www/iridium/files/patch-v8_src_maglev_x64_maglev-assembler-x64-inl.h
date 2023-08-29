--- v8/src/maglev/x64/maglev-assembler-x64-inl.h.orig	2023-08-28 20:17:35 UTC
+++ v8/src/maglev/x64/maglev-assembler-x64-inl.h
@@ -226,7 +226,10 @@ void MaglevAssembler::PushReverse(T... vals) {
   detail::PushAllHelper<T...>::PushReverse(this, vals...);
 }
 
-inline void MaglevAssembler::BindJumpTarget(Label* label) { bind(label); }
+inline void MaglevAssembler::BindJumpTarget(Label* label) {
+  bind(label);
+  endbr64();
+}
 
 inline void MaglevAssembler::BindBlock(BasicBlock* block) {
   bind(block->label());
