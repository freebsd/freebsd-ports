--- deps/v8/src/compiler/backend/ppc/code-generator-ppc.cc.orig	2020-07-20 22:18:45 UTC
+++ deps/v8/src/compiler/backend/ppc/code-generator-ppc.cc
@@ -1038,8 +1038,7 @@ CodeGenerator::CodeGenResult CodeGenerator::AssembleAr
       bool isWasmCapiFunction =
           linkage()->GetIncomingDescriptor()->IsWasmCapiFunction();
       int offset = (FLAG_enable_embedded_constant_pool ? 20 : 23) * kInstrSize;
-
-#if defined(_AIX)
+#if defined(_AIX) || (V8_TARGET_ARCH_PPC_BE && (!defined(_CALL_ELF) || _CALL_ELF == 1))
       // AIX/PPC64BE Linux uses a function descriptor
       int kNumParametersMask = kHasFunctionDescriptorBitMask - 1;
       num_parameters = kNumParametersMask & misc_field;
