- bug#232485: fix build with powerpc*

--- src/libs/vmisc/debugbreak.h.orig	2020-07-11 05:51:16 UTC
+++ src/libs/vmisc/debugbreak.h
@@ -119,6 +119,13 @@ __inline__ static void trap_instruction(void)
      * The workaround is the same as ARM Thumb mode: use debugbreak-gdb.py
      * or manually jump over the instruction. */
 }
+#elif defined(__powerpc__)
+enum { HAVE_TRAP_INSTRUCTION = 1 };
+__attribute__((gnu_inline, always_inline))
+__inline__ static void trap_instruction(void)
+{
+    __asm__ volatile(".4byte 0x7d821008");
+}
 #else
     #define DEBUG_BREAK_IMPL DEBUG_BREAK_USE_SIGTRAP
 #endif
