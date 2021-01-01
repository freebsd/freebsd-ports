--- deps/v8/src/compiler/backend/ppc/code-generator-ppc.cc.orig	2020-04-21 11:38:50 UTC
+++ deps/v8/src/compiler/backend/ppc/code-generator-ppc.cc
@@ -1026,7 +1026,7 @@
       Label start_call;
       bool isWasmCapiFunction =
           linkage()->GetIncomingDescriptor()->IsWasmCapiFunction();
-#if defined(_AIX)
+#if defined(_AIX) || (V8_TARGET_ARCH_PPC_BE && (!defined(_CALL_ELF) || _CALL_ELF == 1))
       // AIX/PPC64BE Linux uses a function descriptor
       int kNumParametersMask = kHasFunctionDescriptorBitMask - 1;
       num_parameters = kNumParametersMask & misc_field;
