--- src/Common/CxDefs.h.orig	2026-09-03 10:18:30 UTC
+++ src/Common/CxDefs.h
@@ -138,7 +138,7 @@
    #endif
 #endif
 
-#if (defined  __GNUC__ || defined __INTEL_COMPILER)
+#if (defined  __GNUC__ || defined __INTEL_COMPILER) && (defined __i386__ || defined __x86_64__)
    // 'insert software breakpoint here'.
    #define DEBUG_BREAK __asm__("int $0x03");
 #elif defined(_MSC_VER) && !defined(__PGI)  // microsoft c++ (other win32 compilers might emulate this syntax)
