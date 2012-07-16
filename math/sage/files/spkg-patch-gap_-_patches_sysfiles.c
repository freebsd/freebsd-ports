--- gap-4.4.12.p6/patches/sysfiles.c.orig	2010-04-29 01:30:00.000000000 +1000
+++ gap-4.4.12.p7/patches/sysfiles.c	2010-07-26 05:25:58.334562226 +1000
@@ -1524,7 +1524,7 @@
 **  to cooked mode before stopping GAP and back to raw mode when continueing.
 */
 
-#if !SYS_IS_DARWIN && (SYS_BSD || SYS_MACH || HAVE_SGTTY_H)
+#if !SYS_IS_DARWIN && (SYS_BSD || SYS_MACH || HAVE_SGTTY_H) && !HAVE_TERMIOS_H
 
 #ifndef SYS_SGTTY_H                     /* terminal control functions      */
 # include       <sgtty.h>
@@ -2073,7 +2073,7 @@
 **
 *f  syStopraw( <fid> )  . . . . . . . . . . . . . . . . . . . . . .  BSD/MACH
 */
-#if !SYS_IS_DARWIN && (SYS_BSD || SYS_MACH || HAVE_SGTTY_H)
+#if !SYS_IS_DARWIN && (SYS_BSD || SYS_MACH || HAVE_SGTTY_H) && !HAVE_TERMIOS_H
 
 void syStopraw (
     Int                 fid )
@@ -2760,7 +2760,7 @@
 **
 *f  syEchoch( <ch>, <fid> ) . . . . . . . . . . . . . . . . . . . .  BSD/MACH
 */
-#if SYS_BSD || SYS_MACH || HAVE_SGTTY_H
+#if (SYS_BSD || SYS_MACH || HAVE_SGTTY_H) && !HAVE_TERMIOS_H
 
 void syEchoch (
     Int                 ch,
@@ -2786,7 +2786,7 @@
 **
 *f  syEchoch( <ch>, <fid> ) . . . . . . . . . . . . . . . . . . . . . . . USG
 */
-#if SYS_USG || HAVE_TERMIO_H
+#if SYS_USG || HAVE_TERMIO_H || HAVE_TERMIOS_H
 
 void syEchoch (
     Int                 ch,
@@ -2974,7 +2974,7 @@
 **
 *f  syEchos( <ch>, <fid> )  . . . . . . . . . . . . . . . . . . . .  BSD/MACH
 */
-#if SYS_BSD || SYS_MACH || HAVE_SGTTY_H
+#if (SYS_BSD || SYS_MACH || HAVE_SGTTY_H) && !HAVE_TERMIOS_H
 
 void syEchos (
     Char *              str,
@@ -2996,7 +2996,7 @@
 **
 *f  syEchos( <ch>, <fid> )  . . . . . . . . . . . . . . . . . . . . . . . USG
 */
-#if SYS_USG || HAVE_TERMIO_H
+#if SYS_USG || HAVE_TERMIO_H || HAVE_TERMIOS_H
 
 void syEchos (
     Char *              str,
@@ -3149,7 +3149,7 @@
 **
 *f  SyFputs( <line>, <fid> )  . . . . . . .  BSD/MACH/USG/OS2 EMX/VMS/MAC MPW
 */
-#if SYS_BSD||SYS_MACH||SYS_USG||SYS_OS2_EMX||SYS_VMS||SYS_MAC_MPW||HAVE_SGTTY_H||HAVE_TERMIO_H
+#if SYS_BSD||SYS_MACH||SYS_USG||SYS_OS2_EMX||SYS_VMS||SYS_MAC_MPW||HAVE_SGTTY_H||HAVE_TERMIO_H||HAVE_TERMIOS_H
 
 void SyFputs (
     Char *              line,
@@ -3476,7 +3476,7 @@
 **  that return odd things rather than waiting for a key
 **  
 */
-#if SYS_BSD || SYS_MACH || HAVE_SGTTY_H ||SYS_USG || HAVE_TERMIO_H
+#if SYS_BSD || SYS_MACH || HAVE_SGTTY_H ||SYS_USG || HAVE_TERMIO_H || HAVE_TERMIOS_H
 
 /* In the cygwin environment it is not predictable if text files get the
  * '\r' in their line ends filtered out *before* GAP sees them. This leads
