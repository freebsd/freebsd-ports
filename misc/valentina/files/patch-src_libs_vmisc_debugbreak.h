--- src/libs/vmisc/debugbreak.h.orig	2018-10-20 17:36:33 UTC
+++ src/libs/vmisc/debugbreak.h
@@ -100,6 +100,13 @@ __inline__ static void trap_instruction(void)
      * 'aarch64_default_breakpoint' */
     __asm__ volatile(".inst 0xd4200000");
 }
+#elif defined(__powerpc__)
+enum { HAVE_TRAP_INSTRUCTION = 1 };
+__attribute__((gnu_inline, always_inline))
+__inline__ static void trap_instruction(void)
+{
+    __asm__ volatile(".4byte 0x7d821008");
+}
 #else
 enum { HAVE_TRAP_INSTRUCTION = 0 };
 #endif
