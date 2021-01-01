--- deps/v8/src/execution/simulator.h.orig	2019-11-21 21:14:01 UTC
+++ deps/v8/src/execution/simulator.h
@@ -122,7 +122,7 @@
 
   DISABLE_CFI_ICALL Return Call(Args... args) {
     // When running without a simulator we call the entry directly.
-#if V8_OS_AIX
+#if V8_OS_AIX || (V8_TARGET_ARCH_PPC_BE && (!defined(_CALL_ELF) || _CALL_ELF == 1))
     // AIX ABI requires function descriptors (FD).  Artificially create a pseudo
     // FD to ensure correct dispatch to generated code.  The 'volatile'
     // declaration is required to avoid the compiler from not observing the
