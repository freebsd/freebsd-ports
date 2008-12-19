--- gap4r4/src/sysfiles.c.orig	2006-11-13 07:25:20.000000000 +0100
+++ gap4r4/src/sysfiles.c	2008-06-12 08:23:32.000000000 +0200
@@ -1522,7 +1522,7 @@
 **  to cooked mode before stopping GAP and back to raw mode when continueing.
 */
 
-#if !SYS_IS_DARWIN && (SYS_BSD || SYS_MACH || HAVE_SGTTY_H)
+#if !SYS_IS_DARWIN && (SYS_BSD || SYS_MACH || HAVE_SGTTY_H) && !HAVE_TERMIOS_H
 
 #ifndef SYS_SGTTY_H                     /* terminal control functions      */
 # include       <sgtty.h>
@@ -2072,7 +2072,7 @@
 **
 *f  syStopraw( <fid> )  . . . . . . . . . . . . . . . . . . . . . .  BSD/MACH
 */
-#if !SYS_IS_DARWIN && (SYS_BSD || SYS_MACH || HAVE_SGTTY_H)
+#if !SYS_IS_DARWIN && (SYS_BSD || SYS_MACH || HAVE_SGTTY_H) && !HAVE_TERMIOS_H
 
 void syStopraw (
     Int                 fid )
@@ -2759,7 +2759,7 @@
 **
 *f  syEchoch( <ch>, <fid> ) . . . . . . . . . . . . . . . . . . . .  BSD/MACH
 */
-#if SYS_BSD || SYS_MACH || HAVE_SGTTY_H
+#if (SYS_BSD || SYS_MACH || HAVE_SGTTY_H) && !HAVE_TERMIOS_H
 
 void syEchoch (
     Int                 ch,
@@ -2785,7 +2785,7 @@
 **
 *f  syEchoch( <ch>, <fid> ) . . . . . . . . . . . . . . . . . . . . . . . USG
 */
-#if SYS_USG || HAVE_TERMIO_H
+#if SYS_USG || HAVE_TERMIO_H || HAVE_TERMIOS_H
 
 void syEchoch (
     Int                 ch,
@@ -2973,7 +2973,7 @@
 **
 *f  syEchos( <ch>, <fid> )  . . . . . . . . . . . . . . . . . . . .  BSD/MACH
 */
-#if SYS_BSD || SYS_MACH || HAVE_SGTTY_H
+#if (SYS_BSD || SYS_MACH || HAVE_SGTTY_H) && !HAVE_TERMIOS_H
 
 void syEchos (
     Char *              str,
@@ -2995,7 +2995,7 @@
 **
 *f  syEchos( <ch>, <fid> )  . . . . . . . . . . . . . . . . . . . . . . . USG
 */
-#if SYS_USG || HAVE_TERMIO_H
+#if SYS_USG || HAVE_TERMIO_H || HAVE_TERMIOS_H
 
 void syEchos (
     Char *              str,
@@ -3148,7 +3148,7 @@
 **
 *f  SyFputs( <line>, <fid> )  . . . . . . .  BSD/MACH/USG/OS2 EMX/VMS/MAC MPW
 */
-#if SYS_BSD||SYS_MACH||SYS_USG||SYS_OS2_EMX||SYS_VMS||SYS_MAC_MPW||HAVE_SGTTY_H||HAVE_TERMIO_H
+#if SYS_BSD||SYS_MACH||SYS_USG||SYS_OS2_EMX||SYS_VMS||SYS_MAC_MPW||HAVE_SGTTY_H||HAVE_TERMIO_H||HAVE_TERMIOS_H
 
 void SyFputs (
     Char *              line,
@@ -3475,7 +3475,7 @@
 **  that return odd things rather than waiting for a key
 **  
 */
-#if SYS_BSD || SYS_MACH || HAVE_SGTTY_H ||SYS_USG || HAVE_TERMIO_H
+#if SYS_BSD || SYS_MACH || HAVE_SGTTY_H ||SYS_USG || HAVE_TERMIO_H || HAVE_TERMIOS_H
 
 /* In the cygwin environment it is not predictable if text files get the
  * '\r' in their line ends filtered out *before* GAP sees them. This leads
