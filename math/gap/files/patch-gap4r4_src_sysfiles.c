--- gap4r4/src/sysfiles.c	Mon Oct 23 01:20:54 2006
+++ gap4r4/src/sysfiles.c	Mon Mar 26 18:28:38 2007
@@ -1522,7 +1522,7 @@
 **  to cooked mode before stopping GAP and back to raw mode when continueing.
 */
 
-#if SYS_BSD || SYS_MACH || HAVE_SGTTY_H
+#if (SYS_BSD || SYS_MACH || HAVE_SGTTY_H) && !HAVE_TERMIOS_H
 
 #ifndef SYS_SGTTY_H                     /* terminal control functions      */
 # include       <sgtty.h>
@@ -2072,7 +2072,7 @@
 **
 *f  syStopraw( <fid> )  . . . . . . . . . . . . . . . . . . . . . .  BSD/MACH
 */
-#if SYS_BSD || SYS_MACH || HAVE_SGTTY_H
+#if (SYS_BSD || SYS_MACH || HAVE_SGTTY_H) && !HAVE_TERMIOS_H
 
 void syStopraw (
     Int                 fid )
