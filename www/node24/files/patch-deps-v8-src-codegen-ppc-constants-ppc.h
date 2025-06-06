--- deps/v8/src/codegen/ppc/constants-ppc.h.orig	2025-05-06 12:36:30 UTC
+++ deps/v8/src/codegen/ppc/constants-ppc.h
@@ -35,7 +35,7 @@
 #define ABI_PASSES_HANDLES_IN_REGS 0
 #endif
 
-#if !V8_HOST_ARCH_PPC64 || !V8_TARGET_ARCH_PPC64 || V8_TARGET_LITTLE_ENDIAN || \
+#if !V8_HOST_ARCH_PPC64 || !V8_TARGET_ARCH_PPC64 || \
     (defined(_CALL_ELF) && _CALL_ELF == 2)
 #define ABI_RETURNS_OBJECT_PAIRS_IN_REGS 1
 #else
@@ -44,7 +44,7 @@
 
 #if !V8_HOST_ARCH_PPC64 ||   \
     (V8_TARGET_ARCH_PPC64 && \
-     (V8_TARGET_LITTLE_ENDIAN || (defined(_CALL_ELF) && _CALL_ELF == 2)))
+     (defined(_CALL_ELF) && _CALL_ELF == 2))
 #define ABI_CALL_VIA_IP 1
 #else
 #define ABI_CALL_VIA_IP 0
