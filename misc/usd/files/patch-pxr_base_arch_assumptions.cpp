--- pxr/base/arch/assumptions.cpp.orig	2025-10-24 16:21:56 UTC
+++ pxr/base/arch/assumptions.cpp
@@ -20,6 +20,8 @@
 
 #if defined(ARCH_OS_LINUX)
 #include <unistd.h>
+#elif defined(ARCH_OS_FREEBSD)
+#include <sys/param.h>
 #elif defined(ARCH_OS_DARWIN)
 #include <sys/sysctl.h>
 #include <mach-o/arch.h>
@@ -35,6 +37,8 @@ Arch_ObtainCacheLineSize()
 {
 #if defined(ARCH_OS_LINUX)
     return sysconf(_SC_LEVEL1_DCACHE_LINESIZE);
+#elif defined(ARCH_OS_FREEBSD)
+    return CACHE_LINE_SIZE;
 #elif defined(ARCH_OS_WASM_VM)
     return 64;
 #elif defined(ARCH_OS_DARWIN)
