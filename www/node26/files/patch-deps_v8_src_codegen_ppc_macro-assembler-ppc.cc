--- deps/v8/src/codegen/ppc/macro-assembler-ppc.cc.orig	2026-09-21 21:15:56 UTC
+++ deps/v8/src/codegen/ppc/macro-assembler-ppc.cc
@@ -257,6 +257,7 @@ void MacroAssembler::Call(Register targe
   // branch via link register and set LK bit for return point
   mtctr(target);
   bctrl();
+  RecordPcForSafepoint();
 }
 
 void MacroAssembler::CallJSEntry(Register target) {
@@ -284,6 +285,7 @@ void MacroAssembler::Call(Address target
   mov(ip, Operand(target, rmode));
   mtctr(ip);
   bctrl();
+  RecordPcForSafepoint();
 }
 
 void MacroAssembler::Call(Handle<Code> code, RelocInfo::Mode rmode,
@@ -417,7 +419,10 @@ Operand MacroAssembler::ClearedValue() c
   return Operand(static_cast<int32_t>(i::kClearedWeakValue.ptr()));
 }
 
-void MacroAssembler::Call(Label* target) { b(target, SetLK); }
+void MacroAssembler::Call(Label* target) {
+  b(target, SetLK);
+  RecordPcForSafepoint();
+}
 
 void MacroAssembler::Push(Handle<HeapObject> handle) {
   mov(r0, Operand(handle));
