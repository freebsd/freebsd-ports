--- server.c	Tue Jun  4 21:40:19 2002
+++ server.c	Tue Jun  4 21:42:56 2002
@@ -54,7 +54,6 @@
 #endif /* USG5 || SVR4 */
 
 #include <sys/param.h>
-#include <sgtty.h>
 #include <sys/types.h>
 #include <ctype.h>
 
@@ -66,7 +65,7 @@
 #else
 char *malloc();
 #endif
-long time();
+time_t time();
 uid_t getuid();
 char *progname;
 int debug = 0;
@@ -99,6 +98,9 @@
      }
 
      if (! strcmp (basename (progname), "rmsgd")) {
+#if (defined(BSD) && (BSD >= 199306))
+	(void)daemon(0,0);
+#else
           if (fork()) _exit(0);  /* make myself a daemon */
 #ifdef BSD
           fd = open("/dev/tty", O_RDWR);  /* disconnect from control tty */
@@ -109,10 +111,11 @@
 #else
           (void) setpgrp ();
 #endif
+#endif
      }
 
      else {
-          (void) fprintf (stderr, "Starting from inetd not yet supported, rename me ase rmsgd and start\nfrom /etc/rc\n");
+          (void) fprintf (stderr, "Starting from inetd not yet supported, rename me ase rmsgd and start\nfrom /etc/rc.local\n");
      }
 
      if (argc > 1)
@@ -142,7 +145,7 @@
 {
      int child, pid, fd;
      unsigned int retval = 0;
-#if defined(HPUX) || defined(SVR4)
+#if defined(HPUX) || defined(SVR4) || defined(BSD)
      int status;
 #else
      union wait status;
@@ -198,6 +201,9 @@
 #if defined(HPUX) || defined(SVR4)
           if (status & 0xff) retval = -1;
           else retval = ((status & 0xffff) >> 8);
+#elif defined(BSD)
+          if (WIFSIGNALED(status)) retval = -1;
+          else retval = WEXITSTATUS(status);
 #else
           if (status.w_termsig) retval = -1;       /* ended in signal */
           else retval = status.w_retcode;
