--- deps/v8/src/compiler/backend/instruction-selector.cc.orig	2019-12-03 12:54:01 UTC
+++ deps/v8/src/compiler/backend/instruction-selector.cc
@@ -2812,7 +2812,7 @@ void InstructionSelector::VisitCall(Node* node, BasicB
   switch (call_descriptor->kind()) {
     case CallDescriptor::kCallAddress: {
       int misc_field = static_cast<int>(call_descriptor->ParameterCount());
-#if defined(_AIX)
+#if defined(_AIX) || (V8_TARGET_ARCH_PPC_BE && (!defined(_CALL_ELF) || _CALL_ELF == 1))
       // Highest misc_field bit is used on AIX to indicate if a CFunction call
       // has function descriptor or not.
       misc_field |= call_descriptor->HasFunctionDescriptor()
