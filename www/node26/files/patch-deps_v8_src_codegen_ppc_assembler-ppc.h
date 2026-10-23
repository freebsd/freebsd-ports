--- deps/v8/src/codegen/ppc/assembler-ppc.h.orig	2026-09-21 21:15:56 UTC
+++ deps/v8/src/codegen/ppc/assembler-ppc.h
@@ -205,6 +205,13 @@ class Assembler : public AssemblerBase {
   // Unused on this architecture.
   void ClearInternalState() {}
 
+  // On PPC64, we sometimes need to emit branch trampolines between emitting
+  // a call instruction (bctrl) and recording a safepoint. This means that
+  // we have to be careful to make sure the safepoint is recorded at the right
+  // position. So we record the pc right after emitting the call instruction
+  // and use this for the safepoint.
+  int pc_offset_for_safepoint() const { return pc_offset_for_safepoint_; }
+
   inline void CheckTrampolinePoolQuick(int extra_space = 0) {
     if (pc_offset() >= next_trampoline_check_ - extra_space) {
       CheckTrampolinePool();
@@ -1364,6 +1371,8 @@ class Assembler : public AssemblerBase {
 
   // Record reloc info for current pc_
   void RecordRelocInfo(RelocInfo::Mode rmode, intptr_t data = 0);
+
+  void RecordPcForSafepoint() { pc_offset_for_safepoint_ = pc_offset(); }
   ConstantPoolEntry::Access ConstantPoolAddEntry(RelocInfo::Mode rmode,
                                                  intptr_t value) {
     bool sharing_ok =
@@ -1445,6 +1454,11 @@ class Assembler : public AssemblerBase {
 
   // The bound position, before this we cannot do instruction elimination.
   int last_bound_pos_;
+
+  // Keep track of the last call instruction (bctrl/bl) position to ensure that
+  // we can generate a correct safepoint even in the presence of a branch
+  // trampoline between emitting the call and recording the safepoint.
+  int pc_offset_for_safepoint_ = -1;
   // Optimizable cmpi information.
   int optimizable_cmpi_pos_;
   CRegister cmpi_cr_ = CRegister::no_reg();
