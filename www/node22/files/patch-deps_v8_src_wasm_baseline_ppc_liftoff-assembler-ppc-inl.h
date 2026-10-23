--- deps/v8/src/wasm/baseline/ppc/liftoff-assembler-ppc-inl.h.orig	2026-07-28 22:07:50 UTC
+++ deps/v8/src/wasm/baseline/ppc/liftoff-assembler-ppc-inl.h
@@ -2589,7 +2589,7 @@
 
 void LiftoffAssembler::emit_i8x16_bitmask(LiftoffRegister dst,
                                           LiftoffRegister src) {
-  I8x16BitMask(dst.gp(), src.fp().toSimd(), r0, ip, kScratchSimd128Reg);
+  I8x16BitMask(dst.gp(), src.fp().toSimd(), ip, r0, kScratchSimd128Reg);
 }
 
 void LiftoffAssembler::emit_s128_const(LiftoffRegister dst,
