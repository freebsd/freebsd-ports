https://bugs.webkit.org/show_bug.cgi?id=129963

Index: Source/WTF/wtf/PlatformCPU.h
--- Source/WTF/wtf/PlatformCPU.h.orig
+++ Source/WTF/wtf/PlatformCPU.h
@@ -95,6 +95,13 @@
 #define WTF_CPU_KNOWN 1
 #endif
 
+/* CPU(SPARC64) - SPARC V9 */
+#if defined(__sparc64__)
+#define WTF_CPU_KNOWN 1
+#define WTF_CPU_SPARC64 1
+#define WTF_CPU_BIG_ENDIAN 1
+#endif
+
 /* CPU(X86) - i386 / x86 32-bit */
 #if   defined(__i386__) \
     || defined(i386)     \
@@ -295,7 +302,7 @@
 #define WTF_CPU_UNKNOWN 1
 #endif
 
-#if CPU(ARM) || CPU(MIPS) || CPU(RISCV64) || CPU(UNKNOWN)
+#if CPU(ARM) || CPU(MIPS) || CPU(RISCV64) || CPU(SPARC64) || CPU(UNKNOWN)
 #define WTF_CPU_NEEDS_ALIGNED_ACCESS 1
 #endif
 
