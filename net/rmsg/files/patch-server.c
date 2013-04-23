--- server.c	1993-06-26 17:23:23.000000000 -0400
+++ server.c	2013-04-23 17:13:15.000000000 -0400
@@ -24,7 +24,11 @@
 
 #define SERVER
 
+#include <libgen.h>
 #include <stdio.h>
+#include <stdlib.h>
+#include <sys/param.h>
+#include <unistd.h>
 #if defined(SVR4)
 # include <netinet/in.h>
 #endif /* SVR4 */
@@ -39,11 +43,7 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <sys/file.h>
-#if defined(SVR4)
-# include <string.h>
-#else
-# include <strings.h>
-#endif /* SVR4 */
+#include <string.h>
 #include <sys/ioctl.h>
 #ifndef USG5
 #include <sys/wait.h>
@@ -54,19 +54,12 @@
 #endif /* USG5 || SVR4 */
 
 #include <sys/param.h>
-#include <sgtty.h>
 #include <sys/types.h>
 #include <ctype.h>
 
-int xdr_rmsg(), smsg();
+static void smsg(struct svc_req *, SVCXPRT *);
 int tty_write(), dowrite();
-char *basename(), *parseheader();
-#ifdef SUNOS
-void *malloc();
-#else
-char *malloc();
-#endif
-long time();
+char *parseheader();
 uid_t getuid();
 char *progname;
 int debug = 0;
@@ -99,6 +93,9 @@
      }
 
      if (! strcmp (basename (progname), "rmsgd")) {
+#if (defined(BSD) && (BSD >= 199306))
+	(void)daemon(0,0);
+#else
           if (fork()) _exit(0);  /* make myself a daemon */
 #ifdef BSD
           fd = open("/dev/tty", O_RDWR);  /* disconnect from control tty */
@@ -109,10 +106,11 @@
 #else
           (void) setpgrp ();
 #endif
+#endif
      }
 
      else {
-          (void) fprintf (stderr, "Starting from inetd not yet supported, rename me ase rmsgd and start\nfrom /etc/rc\n");
+          (void) fprintf (stderr, "Starting from inetd not yet supported, rename me as rmsgd and start\nfrom /etc/rc.local\n");
      }
 
      if (argc > 1)
@@ -136,13 +134,14 @@
      exit(-3);
 }
 
+void
 smsg(rqstp, transp)
 struct svc_req *rqstp;
 SVCXPRT *transp;
 {
      int child, pid, fd;
      unsigned int retval = 0;
-#if defined(HPUX) || defined(SVR4)
+#if defined(HPUX) || defined(SVR4) || defined(BSD)
      int status;
 #else
      union wait status;
@@ -198,6 +197,9 @@
 #if defined(HPUX) || defined(SVR4)
           if (status & 0xff) retval = -1;
           else retval = ((status & 0xffff) >> 8);
+#elif defined(BSD)
+          if (WIFSIGNALED(status)) retval = -1;
+          else retval = WEXITSTATUS(status);
 #else
           if (status.w_termsig) retval = -1;       /* ended in signal */
           else retval = status.w_retcode;
