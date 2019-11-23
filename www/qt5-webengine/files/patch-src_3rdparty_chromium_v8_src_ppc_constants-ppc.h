--- src/3rdparty/chromium/v8/src/ppc/constants-ppc.h.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/v8/src/ppc/constants-ppc.h
@@ -21,7 +21,8 @@
 #endif
 
 #if V8_HOST_ARCH_PPC && \
-    (V8_OS_AIX || (V8_TARGET_ARCH_PPC64 && V8_TARGET_BIG_ENDIAN))
+    (V8_OS_AIX || (V8_TARGET_ARCH_PPC64 && \
+      (V8_TARGET_BIG_ENDIAN && (!defined(_CALL_ELF) || _CALL_ELF == 1))))
 #define ABI_USES_FUNCTION_DESCRIPTORS 1
 #else
 #define ABI_USES_FUNCTION_DESCRIPTORS 0
@@ -33,13 +34,15 @@
 #define ABI_PASSES_HANDLES_IN_REGS 0
 #endif
 
-#if !V8_HOST_ARCH_PPC || !V8_TARGET_ARCH_PPC64 || V8_TARGET_LITTLE_ENDIAN
+#if !V8_HOST_ARCH_PPC || !V8_TARGET_ARCH_PPC64 || \
+    (V8_TARGET_LITTLE_ENDIAN || (defined(_CALL_ELF) && _CALL_ELF == 2))
 #define ABI_RETURNS_OBJECT_PAIRS_IN_REGS 1
 #else
 #define ABI_RETURNS_OBJECT_PAIRS_IN_REGS 0
 #endif
 
-#if !V8_HOST_ARCH_PPC || (V8_TARGET_ARCH_PPC64 && V8_TARGET_LITTLE_ENDIAN)
+#if !V8_HOST_ARCH_PPC || (V8_TARGET_ARCH_PPC64 && \
+    (V8_TARGET_LITTLE_ENDIAN || (defined(_CALL_ELF) && _CALL_ELF == 2)))
 #define ABI_CALL_VIA_IP 1
 #else
 #define ABI_CALL_VIA_IP 0
