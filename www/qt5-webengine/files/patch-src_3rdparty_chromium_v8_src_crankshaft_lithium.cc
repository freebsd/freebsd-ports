--- src/3rdparty/chromium/v8/src/crankshaft/lithium.cc.orig	2017-04-11 14:08:45 UTC
+++ src/3rdparty/chromium/v8/src/crankshaft/lithium.cc
@@ -125,11 +125,6 @@ void LOperand::PrintTo(StringStream* stream) {
 
 
 template<LOperand::Kind kOperandKind, int kNumCachedOperands>
-LSubKindOperand<kOperandKind, kNumCachedOperands>*
-LSubKindOperand<kOperandKind, kNumCachedOperands>::cache = NULL;
-
-
-template<LOperand::Kind kOperandKind, int kNumCachedOperands>
 void LSubKindOperand<kOperandKind, kNumCachedOperands>::SetUpCache() {
   if (cache) return;
   cache = new LSubKindOperand[kNumCachedOperands];
