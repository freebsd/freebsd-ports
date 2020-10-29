--- deps/v8/src/execution/simulator.h.orig	2019-11-21 21:14:01 UTC
+++ deps/v8/src/execution/simulator.h
@@ -128,7 +128,7 @@ class GeneratedCode {
 #if defined(V8_TARGET_OS_WIN) && !defined(V8_OS_WIN)
     FATAL("Generated code execution not possible during cross-compilation.");
 #endif  // defined(V8_TARGET_OS_WIN) && !defined(V8_OS_WIN)
-#if V8_OS_AIX
+#if V8_OS_AIX || (V8_TARGET_ARCH_PPC_BE && (!defined(_CALL_ELF) || _CALL_ELF == 1))
     // AIX ABI requires function descriptors (FD).  Artificially create a pseudo
     // FD to ensure correct dispatch to generated code.  The 'volatile'
     // declaration is required to avoid the compiler from not observing the
