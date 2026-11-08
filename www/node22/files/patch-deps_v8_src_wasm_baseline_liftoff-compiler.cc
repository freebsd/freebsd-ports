--- deps/v8/src/wasm/baseline/liftoff-compiler.cc.orig	2026-07-28 22:07:50 UTC
+++ deps/v8/src/wasm/baseline/liftoff-compiler.cc
@@ -1026,6 +1026,7 @@ class LiftoffCompiler {
     source_position_table_builder_.AddPosition(
         __ pc_offset(), SourcePosition(ool->position), true);
     __ CallBuiltin(ool->builtin);
+    auto pc_offset_after_call = __ pc_offset_for_safepoint();
     // It is safe to not check for existing safepoint at this address since we
     // just emitted a call.
     auto safepoint = safepoint_table_builder_.DefineSafepoint(&asm_);
@@ -1050,7 +1051,7 @@ class LiftoffCompiler {
 
     DCHECK_EQ(!debug_sidetable_builder_, !ool->debug_sidetable_entry_builder);
     if (V8_UNLIKELY(ool->debug_sidetable_entry_builder)) {
-      ool->debug_sidetable_entry_builder->set_pc_offset(__ pc_offset());
+      ool->debug_sidetable_entry_builder->set_pc_offset(pc_offset_after_call);
     }
     DCHECK_EQ(ool->continuation.get()->is_bound(), is_stack_check || is_tierup);
     if (is_stack_check) {
@@ -1669,7 +1670,7 @@ class LiftoffCompiler {
     VarState exn = __ PopVarState();
     CallBuiltin(Builtin::kWasmThrowRef, MakeSig::Params(kRef), {exn},
                 decoder->position());
-    int pc_offset = __ pc_offset();
+    int pc_offset = __ pc_offset_for_safepoint();
     MaybeOSR();
     EmitLandingPad(decoder, pc_offset);
   }
@@ -3931,7 +3932,7 @@ class LiftoffCompiler {
       DebugSideTableBuilder::AssumeSpilling assume_spilling) {
     if (V8_LIKELY(!debug_sidetable_builder_)) return;
     debug_sidetable_builder_->NewEntry(
-        __ pc_offset(),
+        __ pc_offset_for_safepoint(),
         GetCurrentDebugSideTableEntries(decoder, assume_spilling).as_vector());
   }
 
@@ -5156,10 +5157,10 @@ class LiftoffCompiler {
                 {VarState{kIntPtrKind, exception_tag, 0},
                  VarState{kIntPtrKind, values_array, 0}},
                 decoder->position());
+    int pc_offset = __ pc_offset_for_safepoint();
 
     RegisterDebugSideTableEntry(decoder, DebugSideTableBuilder::kDidSpill);
 
-    int pc_offset = __ pc_offset();
     MaybeOSR();
     EmitLandingPad(decoder, pc_offset);
   }
@@ -7871,7 +7872,8 @@ class LiftoffCompiler {
         source_position_table_builder_.AddPosition(
             __ pc_offset(), SourcePosition(decoder->position()), true);
         __ CallIndirect(&sig, call_descriptor, target);
-        FinishCall(decoder, &sig, call_descriptor);
+        int pc_offset = __ pc_offset_for_safepoint();
+        FinishCall(decoder, &sig, call_descriptor, pc_offset);
       }
     } else {
       // Inlining direct calls isn't speculative, but existence of the
@@ -7899,7 +7901,8 @@ class LiftoffCompiler {
         source_position_table_builder_.AddPosition(
             __ pc_offset(), SourcePosition(decoder->position()), true);
         __ CallNativeWasmCode(addr);
-        FinishCall(decoder, &sig, call_descriptor);
+        int pc_offset = __ pc_offset_for_safepoint();
+        FinishCall(decoder, &sig, call_descriptor, pc_offset);
       }
     }
   }
@@ -8125,7 +8128,8 @@ class LiftoffCompiler {
             __ pc_offset(), SourcePosition(decoder->position()), true);
         __ CallIndirect(&sig, call_descriptor, target);
 
-        FinishCall(decoder, &sig, call_descriptor);
+        int pc_offset = __ pc_offset_for_safepoint();
+        FinishCall(decoder, &sig, call_descriptor, pc_offset);
       }
     }
   }
@@ -8246,7 +8250,8 @@ class LiftoffCompiler {
           __ pc_offset(), SourcePosition(decoder->position()), true);
       __ CallIndirect(&sig, call_descriptor, target_reg);
 
-      FinishCall(decoder, &sig, call_descriptor);
+      int pc_offset = __ pc_offset_for_safepoint();
+      FinishCall(decoder, &sig, call_descriptor, pc_offset);
     }
   }
 
@@ -8400,12 +8405,12 @@ class LiftoffCompiler {
   }
 
   void FinishCall(FullDecoder* decoder, ValueKindSig* sig,
-                  compiler::CallDescriptor* call_descriptor) {
-    DefineSafepoint();
+                  compiler::CallDescriptor* call_descriptor,
+                  int pc_offset_after_call) {
+    DefineSafepoint(pc_offset_after_call);
     RegisterDebugSideTableEntry(decoder, DebugSideTableBuilder::kDidSpill);
-    int pc_offset = __ pc_offset();
     MaybeOSR();
-    EmitLandingPad(decoder, pc_offset);
+    EmitLandingPad(decoder, pc_offset_after_call);
     __ FinishCall(sig, call_descriptor);
   }
 
