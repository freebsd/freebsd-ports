--- ./H/absmi.h.orig	2013-11-02 21:11:04.000000000 -0200
+++ ./H/absmi.h	2013-11-02 21:11:12.000000000 -0200
@@ -74,7 +74,7 @@
 * Use bp as PREG for X86 machines		               *
 ***************************************************************/
 #if defined(IN_ABSMI_C)
-register struct yami* P1REG asm ("bp"); /* can't use yamop before Yap.h */
+struct yami* P1REG asm ("bp"); /* can't use yamop before Yap.h */
 #define PREG P1REG
 #endif
 #define NEEDS_TO_SET_PC 1
