--- packages/arb-avm-cpp/avm/src/machine.cpp.orig	2022-01-18 18:44:56 UTC
+++ packages/arb-avm-cpp/avm/src/machine.cpp
@@ -95,11 +95,11 @@ Assertion Machine::run() {
     if (auto sideload_blocked = std::get_if<SideloadBlocked>(&block_reason)) {
         sideload_block_number = sideload_blocked->block_number;
     }
-    return {intx::narrow_cast<uint64_t>(machine_state.output.total_steps -
+    return {narrow_cast<uint64_t>(machine_state.output.total_steps -
                                         start_steps),
-            intx::narrow_cast<uint64_t>(machine_state.output.arb_gas_used -
+            narrow_cast<uint64_t>(machine_state.output.arb_gas_used -
                                         start_gas),
-            intx::narrow_cast<uint64_t>(machine_state.getTotalMessagesRead() -
+            narrow_cast<uint64_t>(machine_state.getTotalMessagesRead() -
                                         initialConsumed),
             std::move(machine_state.context.sends),
             std::move(machine_state.context.logs),
