--- src/ptytty.c.orig	Fri Nov 19 07:43:59 2004
+++ src/ptytty.c	Tue Jan 18 19:26:30 2005
@@ -48,7 +48,6 @@
 # include <sys/ioctl.h>
 #endif
 #if defined(PTYS_ARE_PTMX) && !defined(__CYGWIN32__)
-# include <sys/stropts.h>      /* for I_PUSH */
 #endif
 
 
@@ -71,6 +70,11 @@
 rxvt_get_pty(int *fd_tty, const char **ttydev)
 {
     int             pfd;
+
+    if ((pfd = posix_openpt(O_RDWR | O_NOCTTY)) != -1)
+      *ttydev = ptsname(pfd);
+    
+    return pfd;
 
 #ifdef PTYS_ARE_OPENPTY
     char            tty_name[sizeof "/dev/pts/????\0"];
