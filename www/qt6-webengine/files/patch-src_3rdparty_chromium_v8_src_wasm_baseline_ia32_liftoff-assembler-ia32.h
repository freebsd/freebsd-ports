--- src/3rdparty/chromium/v8/src/wasm/baseline/ia32/liftoff-assembler-ia32.h.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/v8/src/wasm/baseline/ia32/liftoff-assembler-ia32.h
@@ -434,7 +434,7 @@ void LiftoffAssembler::Load(LiftoffRegister dst, Regis
 }
 
 void LiftoffAssembler::Load(LiftoffRegister dst, Register src_addr,
-                            Register offset_reg, uint32_t offset_imm,
+                            Register offset_reg, uintptr_t offset_imm,
                             LoadType type, LiftoffRegList pinned,
                             uint32_t* protected_load_pc, bool is_load_mem,
                             bool i64_offset) {
@@ -511,7 +511,7 @@ void LiftoffAssembler::Store(Register dst_addr, Regist
 }
 
 void LiftoffAssembler::Store(Register dst_addr, Register offset_reg,
-                             uint32_t offset_imm, LiftoffRegister src,
+                             uintptr_t offset_imm, LiftoffRegister src,
                              StoreType type, LiftoffRegList pinned,
                              uint32_t* protected_store_pc, bool is_store_mem) {
   DCHECK_EQ(type.value_type() == kWasmI64, src.is_gp_pair());
@@ -579,7 +579,7 @@ void LiftoffAssembler::AtomicLoad(LiftoffRegister dst,
 }
 
 void LiftoffAssembler::AtomicLoad(LiftoffRegister dst, Register src_addr,
-                                  Register offset_reg, uint32_t offset_imm,
+                                  Register offset_reg, uintptr_t offset_imm,
                                   LoadType type, LiftoffRegList pinned) {
   if (type.value() != LoadType::kI64Load) {
     Load(dst, src_addr, offset_reg, offset_imm, type, pinned, nullptr, true);
@@ -598,7 +598,7 @@ void LiftoffAssembler::AtomicStore(Register dst_addr, 
 }
 
 void LiftoffAssembler::AtomicStore(Register dst_addr, Register offset_reg,
-                                   uint32_t offset_imm, LiftoffRegister src,
+                                   uintptr_t offset_imm, LiftoffRegister src,
                                    StoreType type, LiftoffRegList pinned) {
   DCHECK_NE(offset_reg, no_reg);
   DCHECK_LE(offset_imm, std::numeric_limits<int32_t>::max());
@@ -938,7 +938,7 @@ void LiftoffAssembler::AtomicAdd(Register dst_addr, Re
 }  // namespace liftoff
 
 void LiftoffAssembler::AtomicAdd(Register dst_addr, Register offset_reg,
-                                 uint32_t offset_imm, LiftoffRegister value,
+                                 uintptr_t offset_imm, LiftoffRegister value,
                                  LiftoffRegister result, StoreType type) {
   if (type.value() == StoreType::kI64Store) {
     liftoff::AtomicBinop64(this, liftoff::kAdd, dst_addr, offset_reg,
@@ -951,7 +951,7 @@ void LiftoffAssembler::AtomicSub(Register dst_addr, Re
 }
 
 void LiftoffAssembler::AtomicSub(Register dst_addr, Register offset_reg,
-                                 uint32_t offset_imm, LiftoffRegister value,
+                                 uintptr_t offset_imm, LiftoffRegister value,
                                  LiftoffRegister result, StoreType type) {
   if (type.value() == StoreType::kI64Store) {
     liftoff::AtomicBinop64(this, liftoff::kSub, dst_addr, offset_reg,
@@ -963,7 +963,7 @@ void LiftoffAssembler::AtomicAnd(Register dst_addr, Re
 }
 
 void LiftoffAssembler::AtomicAnd(Register dst_addr, Register offset_reg,
-                                 uint32_t offset_imm, LiftoffRegister value,
+                                 uintptr_t offset_imm, LiftoffRegister value,
                                  LiftoffRegister result, StoreType type) {
   if (type.value() == StoreType::kI64Store) {
     liftoff::AtomicBinop64(this, liftoff::kAnd, dst_addr, offset_reg,
@@ -976,7 +976,7 @@ void LiftoffAssembler::AtomicOr(Register dst_addr, Reg
 }
 
 void LiftoffAssembler::AtomicOr(Register dst_addr, Register offset_reg,
-                                uint32_t offset_imm, LiftoffRegister value,
+                                uintptr_t offset_imm, LiftoffRegister value,
                                 LiftoffRegister result, StoreType type) {
   if (type.value() == StoreType::kI64Store) {
     liftoff::AtomicBinop64(this, liftoff::kOr, dst_addr, offset_reg, offset_imm,
@@ -989,7 +989,7 @@ void LiftoffAssembler::AtomicXor(Register dst_addr, Re
 }
 
 void LiftoffAssembler::AtomicXor(Register dst_addr, Register offset_reg,
-                                 uint32_t offset_imm, LiftoffRegister value,
+                                 uintptr_t offset_imm, LiftoffRegister value,
                                  LiftoffRegister result, StoreType type) {
   if (type.value() == StoreType::kI64Store) {
     liftoff::AtomicBinop64(this, liftoff::kXor, dst_addr, offset_reg,
@@ -1002,7 +1002,7 @@ void LiftoffAssembler::AtomicExchange(Register dst_add
 }
 
 void LiftoffAssembler::AtomicExchange(Register dst_addr, Register offset_reg,
-                                      uint32_t offset_imm,
+                                      uintptr_t offset_imm,
                                       LiftoffRegister value,
                                       LiftoffRegister result, StoreType type) {
   if (type.value() == StoreType::kI64Store) {
@@ -1016,7 +1016,7 @@ void LiftoffAssembler::AtomicCompareExchange(
 }
 
 void LiftoffAssembler::AtomicCompareExchange(
-    Register dst_addr, Register offset_reg, uint32_t offset_imm,
+    Register dst_addr, Register offset_reg, uintptr_t offset_imm,
     LiftoffRegister expected, LiftoffRegister new_value, LiftoffRegister result,
     StoreType type) {
   // We expect that the offset has already been added to {dst_addr}, and no
