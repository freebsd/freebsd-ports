--- src/sudosh.c.orig	Tue Oct 26 18:01:24 2004
+++ src/sudosh.c	Thu Oct 28 15:18:50 2004
@@ -75,6 +75,12 @@
 #define SIGCHLD	SIGCLD
 #endif
 
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#include <sys/ioctl.h>
+#include <libutil.h>
+#endif
+
 static struct termios termorig;
 static struct winsize winorig;
 
@@ -377,15 +383,24 @@
     {
       if ((p->mfd = open ("/dev/ptc", O_RDWR)) == -1)
 	{
-	  perror ("Cannot open cloning master pty");
-	  return -1;
+#ifdef __FreeBSD__
+          if (openpty(&p->mfd, &p->sfd, sname, NULL, NULL) == -1)
+	    {
+#endif
+	    perror ("Cannot open cloning master pty");
+	    return -1;
+#ifdef __FreeBSD__
+	  }
+#endif
 	}
     }
 
   (void) unlockpt (p->mfd);
   (void) grantpt (p->mfd);
 
+#ifndef __FreeBSD__
   sname = (char *) ptsname (p->mfd);
+#endif
 
   if ((p->sfd = open (sname, O_RDWR)) == -1)
     {
