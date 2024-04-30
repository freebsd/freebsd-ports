--- src/3rdparty/chromium/v8/src/maglev/x64/maglev-assembler-x64-inl.h.orig	2023-09-13 12:11:42 UTC
+++ src/3rdparty/chromium/v8/src/maglev/x64/maglev-assembler-x64-inl.h
@@ -229,7 +229,10 @@ void MaglevAssembler::PushReverse(T... vals) {
   detail::PushAllHelper<T...>::PushReverse(this, vals...);
 }
 
-inline void MaglevAssembler::BindJumpTarget(Label* label) { bind(label); }
+inline void MaglevAssembler::BindJumpTarget(Label* label) {
+  bind(label);
+  endbr64();
+}
 
 inline void MaglevAssembler::BindBlock(BasicBlock* block) {
   bind(block->label());
