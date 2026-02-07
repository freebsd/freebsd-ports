--- vgseer/ptytty.c.orig	Mon Apr 25 18:21:55 2005
+++ vgseer/ptytty.c	Tue Sep  6 15:43:01 2005
@@ -60,7 +60,6 @@
 # include <sys/ioctl.h>
 #endif
 #if defined(PTYS_ARE_PTMX) && !defined(__CYGWIN32__)
-# include <sys/stropts.h>      /* for I_PUSH */
 #endif
 
 
@@ -83,6 +82,11 @@
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
