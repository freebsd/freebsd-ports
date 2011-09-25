--- src/ia32/lithium-codegen-ia32.cc.orig	2011-09-23 17:00:54.000000000 +0800
+++ src/ia32/lithium-codegen-ia32.cc	2011-09-23 17:01:10.000000000 +0800
@@ -3175,7 +3175,6 @@ void LCodeGen::DoStoreKeyedFastElement(L
 void LCodeGen::DoStoreKeyedFastDoubleElement(
     LStoreKeyedFastDoubleElement* instr) {
   XMMRegister value = ToDoubleRegister(instr->value());
-  Register key = instr->key()->IsRegister() ? ToRegister(instr->key()) : no_reg;
   Label have_value;
 
   __ ucomisd(value, value);
