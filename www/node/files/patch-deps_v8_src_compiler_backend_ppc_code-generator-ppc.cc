--- deps/v8/src/compiler/backend/ppc/code-generator-ppc.cc.orig	2020-04-21 11:38:50 UTC
+++ deps/v8/src/compiler/backend/ppc/code-generator-ppc.cc
@@ -1032,7 +1032,7 @@ CodeGenerator::CodeGenResult CodeGenerator::AssembleAr
       bool isWasmCapiFunction =
           linkage()->GetIncomingDescriptor()->IsWasmCapiFunction();
       int offset = 9 * kInstrSize;
-#if defined(_AIX)
+#if defined(_AIX) || (V8_TARGET_ARCH_PPC_BE && (!defined(_CALL_ELF) || _CALL_ELF == 1))
       // AIX/PPC64BE Linux uses a function descriptor
       int kNumParametersMask = kHasFunctionDescriptorBitMask - 1;
       num_parameters = kNumParametersMask & misc_field;
