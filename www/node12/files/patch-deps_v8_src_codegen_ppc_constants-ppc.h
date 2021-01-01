--- deps/v8/src/codegen/ppc/constants-ppc.h.orig	2019-09-09 16:27:17 UTC
+++ deps/v8/src/codegen/ppc/constants-ppc.h
@@ -34,7 +34,7 @@
 #define ABI_PASSES_HANDLES_IN_REGS 0
 #endif
 
-#if !V8_HOST_ARCH_PPC || !V8_TARGET_ARCH_PPC64 || V8_TARGET_LITTLE_ENDIAN || \
+#if !V8_HOST_ARCH_PPC || !V8_TARGET_ARCH_PPC64 || \
     (defined(_CALL_ELF) && _CALL_ELF == 2)
 #define ABI_RETURNS_OBJECT_PAIRS_IN_REGS 1
 #else
@@ -43,7 +43,7 @@
 
 #if !V8_HOST_ARCH_PPC ||     \
     (V8_TARGET_ARCH_PPC64 && \
-     (V8_TARGET_LITTLE_ENDIAN || (defined(_CALL_ELF) && _CALL_ELF == 2)))
+     (defined(_CALL_ELF) && _CALL_ELF == 2))
 #define ABI_CALL_VIA_IP 1
 #else
 #define ABI_CALL_VIA_IP 0
