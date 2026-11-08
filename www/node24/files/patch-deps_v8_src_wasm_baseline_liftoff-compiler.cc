--- deps/v8/src/wasm/baseline/liftoff-compiler.cc.orig	2026-09-08 00:10:01 UTC
+++ deps/v8/src/wasm/baseline/liftoff-compiler.cc
@@ -1140,6 +1140,7 @@ class LiftoffCompiler {
     source_position_table_builder_.AddPosition(
         __ pc_offset(), SourcePosition(ool->position), true);
     __ CallBuiltin(ool->builtin);
+    auto pc_offset_after_call = __ pc_offset_for_safepoint();
     // It is safe to not check for existing safepoint at this address since we
     // just emitted a call.
     auto safepoint = safepoint_table_builder_.DefineSafepoint(&asm_);
@@ -1164,7 +1165,7 @@ class LiftoffCompiler {
 
     DCHECK_EQ(!debug_sidetable_builder_, !ool->debug_sidetable_entry_builder);
     if (V8_UNLIKELY(ool->debug_sidetable_entry_builder)) {
-      ool->debug_sidetable_entry_builder->set_pc_offset(__ pc_offset());
+      ool->debug_sidetable_entry_builder->set_pc_offset(pc_offset_after_call);
     }
     DCHECK_EQ(ool->continuation.get()->is_bound(), is_stack_check || is_tierup);
     if (is_stack_check) {
@@ -1788,7 +1789,7 @@ class LiftoffCompiler {
     VarState exn = __ PopVarState();
     CallBuiltin(Builtin::kWasmThrowRef, MakeSig::Params(kRef), {exn},
                 decoder->position());
-    int pc_offset = __ pc_offset();
+    int pc_offset = __ pc_offset_for_safepoint();
     MaybeOSR();
     EmitLandingPad(decoder, pc_offset);
   }
@@ -4182,7 +4183,7 @@ class LiftoffCompiler {
       DebugSideTableBuilder::AssumeSpilling assume_spilling) {
     if (V8_LIKELY(!debug_sidetable_builder_)) return;
     debug_sidetable_builder_->NewEntry(
-        __ pc_offset(),
+        __ pc_offset_for_safepoint(),
         GetCurrentDebugSideTableEntries(decoder, assume_spilling).as_vector());
   }
 
@@ -5620,10 +5621,10 @@ class LiftoffCompiler {
                 {VarState{kIntPtrKind, exception_tag, 0},
                  VarState{kIntPtrKind, values_array, 0}},
                 decoder->position());
+    int pc_offset = __ pc_offset_for_safepoint();
 
     RegisterDebugSideTableEntry(decoder, DebugSideTableBuilder::kDidSpill);
 
-    int pc_offset = __ pc_offset();
     MaybeOSR();
     EmitLandingPad(decoder, pc_offset);
   }
@@ -8543,7 +8544,8 @@ class LiftoffCompiler {
         source_position_table_builder_.AddPosition(
             __ pc_offset(), SourcePosition(decoder->position()), true);
         __ CallIndirect(&sig, call_descriptor, target);
-        FinishCall(decoder, &sig, call_descriptor);
+        int pc_offset = __ pc_offset_for_safepoint();
+        FinishCall(decoder, &sig, call_descriptor, pc_offset);
       }
     } else {
       // Update call counts for inlining.
@@ -8571,7 +8573,8 @@ class LiftoffCompiler {
         source_position_table_builder_.AddPosition(
             __ pc_offset(), SourcePosition(decoder->position()), true);
         __ CallNativeWasmCode(addr);
-        FinishCall(decoder, &sig, call_descriptor);
+        int pc_offset = __ pc_offset_for_safepoint();
+        FinishCall(decoder, &sig, call_descriptor, pc_offset);
       }
     }
   }
@@ -8913,7 +8916,8 @@ class LiftoffCompiler {
         source_position_table_builder_.AddPosition(
             __ pc_offset(), SourcePosition(decoder->position()), true);
         __ CallIndirect(&sig, call_descriptor, target);
-        FinishCall(decoder, &sig, call_descriptor);
+        int pc_offset = __ pc_offset_for_safepoint();
+        FinishCall(decoder, &sig, call_descriptor, pc_offset);
       }
     }
   }
@@ -9066,7 +9070,8 @@ class LiftoffCompiler {
       source_position_table_builder_.AddPosition(
           __ pc_offset(), SourcePosition(decoder->position()), true);
       __ CallIndirect(&sig, call_descriptor, target_reg);
-      FinishCall(decoder, &sig, call_descriptor);
+      int pc_offset = __ pc_offset_for_safepoint();
+      FinishCall(decoder, &sig, call_descriptor, pc_offset);
     }
   }
 
@@ -9217,8 +9222,9 @@ class LiftoffCompiler {
   }
 
   void FinishCall(FullDecoder* decoder, ValueKindSig* sig,
-                  compiler::CallDescriptor* call_descriptor) {
-    DefineSafepoint();
+                  compiler::CallDescriptor* call_descriptor,
+                  int pc_offset_after_call) {
+    DefineSafepoint(pc_offset_after_call);
     RegisterDebugSideTableEntry(decoder, DebugSideTableBuilder::kDidSpill);
 
     if (deopt_info_bytecode_offset_ == decoder->pc_offset() &&
@@ -9242,9 +9248,8 @@ class LiftoffCompiler {
       StoreFrameDescriptionForDeopt(decoder, adapt_shadow_stack_pc_offset);
     }
 
-    int pc_offset = __ pc_offset();
     MaybeOSR();
-    EmitLandingPad(decoder, pc_offset);
+    EmitLandingPad(decoder, pc_offset_after_call);
     __ FinishCall(sig, call_descriptor);
   }
 
