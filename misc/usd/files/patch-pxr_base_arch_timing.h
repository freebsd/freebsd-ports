--- pxr/base/arch/timing.h.orig	2025-10-24 16:21:56 UTC
+++ pxr/base/arch/timing.h
@@ -19,7 +19,7 @@
 /// \addtogroup group_arch_SystemFunctions
 ///@{
 
-#if defined(ARCH_OS_LINUX) && defined(ARCH_CPU_INTEL)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_FREEBSD) || defined(ARCH_OS_FREEBSD) && defined(ARCH_CPU_INTEL)
 #include <x86intrin.h>
 #elif defined(ARCH_OS_WASM_VM)
 #include <emscripten.h>
