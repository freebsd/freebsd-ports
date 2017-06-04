--- src/3rdparty/chromium/v8/src/crankshaft/lithium.h.orig	2017-04-11 14:08:45 UTC
+++ src/3rdparty/chromium/v8/src/crankshaft/lithium.h
@@ -344,6 +344,11 @@ LITHIUM_OPERAND_LIST(LITHIUM_TYPEDEF_SUBKIND_OPERAND_C
 #undef LITHIUM_TYPEDEF_SUBKIND_OPERAND_CLASS
 
 
+template<LOperand::Kind kOperandKind, int kNumCachedOperands>
+LSubKindOperand<kOperandKind, kNumCachedOperands>*
+LSubKindOperand<kOperandKind, kNumCachedOperands>::cache = NULL;
+
+
 class LParallelMove final : public ZoneObject {
  public:
   explicit LParallelMove(Zone* zone) : move_operands_(4, zone) { }
