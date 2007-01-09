--- codecs/libfaad2/output.c.orig	Fri May  6 00:34:38 2005
+++ codecs/libfaad2/output.c	Tue Oct  3 02:29:41 2006
@@ -97,8 +97,10 @@
 #define RENAME(a) a ## _c
 #include "i386/output.h"
 
+#if 0
 #if defined( ARCH_X86 ) || defined(ARCH_X86_64)
 #define CAN_COMPILE_X86_ASM
+#endif
 #endif
 
 #ifdef CAN_COMPILE_X86_ASM
