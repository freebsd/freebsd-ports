--- deps/v8/src/maglev/ppc/maglev-assembler-ppc-inl.h.orig	2026-09-21 21:15:56 UTC
+++ deps/v8/src/maglev/ppc/maglev-assembler-ppc-inl.h
@@ -1389,7 +1389,7 @@ inline void MaglevAssembler::TestUint8AndJumpIfAnySet(
   Register scratch = temps.AcquireScratch();
 
   mov(scratch, Operand(mask));
-  LoadU32(r0, operand);
+  LoadU8(r0, operand);
   AndU32(r0, scratch, r0, SetRC);
   bne(target);
 }
@@ -1423,7 +1423,7 @@ inline void MaglevAssembler::TestUint8AndJumpIfAllClea
 
   mov(scratch, Operand(mask));
 
-  LoadU32(r0, operand);
+  LoadU8(r0, operand);
   AndU32(r0, scratch, r0, SetRC);
   beq(target);
 }
