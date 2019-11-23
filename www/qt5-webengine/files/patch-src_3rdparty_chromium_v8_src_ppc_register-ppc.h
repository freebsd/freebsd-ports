--- src/3rdparty/chromium/v8/src/ppc/register-ppc.h.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/v8/src/ppc/register-ppc.h
@@ -145,7 +145,8 @@ const int kNumSafepointRegisters = 32;
 // The following constants describe the stack frame linkage area as
 // defined by the ABI.  Note that kNumRequiredStackFrameSlots must
 // satisfy alignment requirements (rounding up if required).
-#if V8_TARGET_ARCH_PPC64 && V8_TARGET_LITTLE_ENDIAN  // ppc64le linux
+#if V8_TARGET_ARCH_PPC64 && (V8_TARGET_LITTLE_ENDIAN || \
+    defined(_CALL_ELF) && _CALL_ELF == 2)
 // [0] back chain
 // [1] condition register save area
 // [2] link register save area
