--- pxr/base/arch/symbols.cpp.orig	2025-10-24 16:21:56 UTC
+++ pxr/base/arch/symbols.cpp
@@ -10,7 +10,7 @@
 #include "pxr/base/arch/symbols.h"
 #include "pxr/base/arch/defines.h"
 
-#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_WASM_VM)
+#if defined(ARCH_OS_LINUX) || defined(ARCH_OS_WASM_VM) || defined(ARCH_OS_FREEBSD)
 #include <dlfcn.h>
 #elif defined(ARCH_OS_DARWIN)
 #include <dlfcn.h>
