--- deps/v8/src/codegen/ppc/macro-assembler-ppc.cc.orig	2026-07-28 22:07:49 UTC
+++ deps/v8/src/codegen/ppc/macro-assembler-ppc.cc
@@ -224,6 +224,7 @@ void MacroAssembler::Call(Register targe
   // branch via link register and set LK bit for return point
   mtctr(target);
   bctrl();
+  RecordPcForSafepoint();
 }
 
 void MacroAssembler::CallJSEntry(Register target) {
@@ -251,6 +252,7 @@ void MacroAssembler::Call(Address target
   mov(ip, Operand(target, rmode));
   mtctr(ip);
   bctrl();
+  RecordPcForSafepoint();
 }
 
 void MacroAssembler::Call(Handle<Code> code, RelocInfo::Mode rmode,
@@ -375,7 +377,10 @@ Operand MacroAssembler::ClearedValue() c
   return Operand(static_cast<int32_t>(i::ClearedValue(isolate()).ptr()));
 }
 
-void MacroAssembler::Call(Label* target) { b(target, SetLK); }
+void MacroAssembler::Call(Label* target) {
+  b(target, SetLK);
+  RecordPcForSafepoint();
+}
 
 void MacroAssembler::Push(Handle<HeapObject> handle) {
   mov(r0, Operand(handle));
