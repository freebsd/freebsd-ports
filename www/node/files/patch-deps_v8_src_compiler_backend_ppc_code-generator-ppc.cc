--- deps/v8/src/compiler/backend/ppc/code-generator-ppc.cc.orig	2019-12-03 11:33:29 UTC
+++ deps/v8/src/compiler/backend/ppc/code-generator-ppc.cc
@@ -1025,7 +1025,7 @@ CodeGenerator::CodeGenResult CodeGenerator::AssembleAr
       Label start_call;
       bool isWasmCapiFunction =
           linkage()->GetIncomingDescriptor()->IsWasmCapiFunction();
-#if defined(_AIX)
+#if defined(_AIX) || (V8_TARGET_ARCH_PPC_BE && (!defined(_CALL_ELF) || _CALL_ELF == 1))
       // AIX/PPC64BE Linux uses a function descriptor
       int kNumParametersMask = kHasFunctionDescriptorBitMask - 1;
       num_parameters = kNumParametersMask & misc_field;
