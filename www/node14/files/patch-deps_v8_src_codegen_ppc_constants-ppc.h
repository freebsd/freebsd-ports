--- deps/v8/src/codegen/ppc/constants-ppc.h.orig	2020-06-30 17:49:17 UTC
+++ deps/v8/src/codegen/ppc/constants-ppc.h
@@ -36,7 +36,7 @@
 #endif
 
 #if !(V8_HOST_ARCH_PPC || V8_HOST_ARCH_PPC64) || !V8_TARGET_ARCH_PPC64 || \
-    V8_TARGET_LITTLE_ENDIAN || (defined(_CALL_ELF) && _CALL_ELF == 2)
+    (defined(_CALL_ELF) && _CALL_ELF == 2)
 #define ABI_RETURNS_OBJECT_PAIRS_IN_REGS 1
 #else
 #define ABI_RETURNS_OBJECT_PAIRS_IN_REGS 0
@@ -44,7 +44,7 @@
 
 #if !(V8_HOST_ARCH_PPC || V8_HOST_ARCH_PPC64) || \
     (V8_TARGET_ARCH_PPC64 &&                     \
-     (V8_TARGET_LITTLE_ENDIAN || (defined(_CALL_ELF) && _CALL_ELF == 2)))
+     (defined(_CALL_ELF) && _CALL_ELF == 2))
 #define ABI_CALL_VIA_IP 1
 #else
 #define ABI_CALL_VIA_IP 0
