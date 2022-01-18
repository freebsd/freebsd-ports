--- packages/arb-avm-cpp/cavm/cmachine.cpp.orig	2022-01-14 20:19:39 UTC
+++ packages/arb-avm-cpp/cavm/cmachine.cpp
@@ -230,14 +230,14 @@ RawAssertionResult executeAssertion(CMachine* m,
 
         // TODO extend usage of uint256
         return {
-            {intx::narrow_cast<uint64_t>(assertion.inbox_messages_consumed),
+            {narrow_cast<uint64_t>(assertion.inbox_messages_consumed),
              returnCharVector(sendData),
              static_cast<int>(assertion.sends.size()),
              returnCharVector(logData), static_cast<int>(assertion.logs.size()),
              returnCharVector(debugPrintData),
              static_cast<int>(assertion.debug_prints.size()),
-             intx::narrow_cast<uint64_t>(assertion.step_count),
-             intx::narrow_cast<uint64_t>(assertion.gas_count)},
+             narrow_cast<uint64_t>(assertion.step_count),
+             narrow_cast<uint64_t>(assertion.gas_count)},
             false};
     } catch (const DataStorage::shutting_down_exception& e) {
         return {makeEmptyAssertion(), true};
