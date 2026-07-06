--- aeron-client/src/main/cpp_wrapper/concurrent/Atomic64.h.orig	2025-11-24 19:20:55 UTC
+++ aeron-client/src/main/cpp_wrapper/concurrent/Atomic64.h
@@ -22,6 +22,8 @@
     #include "concurrent/atomic/Atomic64_gcc_x86_64.h"
 #elif defined(AERON_COMPILER_GCC) && defined(AERON_CPU_ARM)
     #include "concurrent/atomic/Atomic64_gcc_cpp11.h"
+#elif defined(AERON_COMPILER_GCC) && defined(AERON_CPU_PPC64)
+    #include "concurrent/atomic/Atomic64_gcc_cpp11.h"
 #elif defined(AERON_COMPILER_MSVC) && defined(AERON_CPU_X64)
     #include "concurrent/atomic/Atomic64_msvc.h"
 #else
