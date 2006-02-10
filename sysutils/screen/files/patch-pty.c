--- pty.c.orig	Mon Feb  6 18:54:37 2006
+++ pty.c	Mon Feb  6 18:56:50 2006
@@ -33,10 +33,12 @@
 # include <sys/ioctl.h>
 #endif
 
+#ifndef __FreeBSD__
 /* for solaris 2.1, Unixware (SVR4.2) and possibly others */
 #ifdef HAVE_SVR4_PTYS
 # include <sys/stropts.h>
 #endif
+#endif
 
 #if defined(sun) && defined(LOCKPTY) && !defined(TIOCEXCL)
 # include <sys/ttold.h>
