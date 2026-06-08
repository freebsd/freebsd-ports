--- aeron-client/src/main/c/concurrent/aeron_atomic.h.orig	2025-11-24 19:20:55 UTC
+++ aeron-client/src/main/c/concurrent/aeron_atomic.h
@@ -23,6 +23,8 @@
     #include "concurrent/aeron_atomic64_gcc_x86_64.h"
 #elif defined(AERON_COMPILER_GCC) && defined(AERON_CPU_ARM)
     #include "concurrent/aeron_atomic64_c11.h"
+#elif defined(AERON_CPU_PPC64)
+    #include "concurrent/aeron_atomic64_c11.h"
 #elif defined(AERON_COMPILER_MSVC) && defined(AERON_CPU_X64)
     #include "concurrent/aeron_atomic64_msvc.h"
 #else
