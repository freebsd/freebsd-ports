--- programs/IRRd/uii_commands.c.orig	Tue Feb  5 05:53:57 2002
+++ programs/IRRd/uii_commands.c	Thu Apr 22 18:13:29 2004
@@ -14,6 +14,8 @@
 #include <ctype.h>
 #include "irrd.h"
 
+#include <errno.h>
+
 #include <fcntl.h>
 #ifndef SETPGRP_VOID
 #endif
@@ -720,6 +722,10 @@
 
 void run_cmd (char *cmd, FILE **in, FILE **out) {
   int pin[2], pout[2];
+  int pid;
+  int omask, pstat;
+  pid_t ppid;
+  extern int errno;
 
   if (in != NULL)
     *in = NULL;
@@ -733,7 +739,9 @@
   if (out != NULL)
     pipe (pout);
   
-  if (fork() == 0) { /* We're the child */
+/*  if (fork() == 0) { */
+  pid = fork();
+  if (pid == 0) { /* We're the child */
     if (in != NULL) {
       close (pin[1]);
       dup2  (pin[0], 0);
@@ -747,7 +755,7 @@
       close (pout[1]);
     }
     
-    execl("/bin/sh", "sh", "-c", cmd, NULL);
+    execlp("/bin/sh", "sh", "-c", cmd, NULL);
     _exit(127);
   }
 
@@ -761,6 +769,12 @@
     close (pin[0]);
     *in = fdopen (pin[1], "w");
   }
+
+  omask = sigblock(sigmask(SIGINT)|sigmask(SIGQUIT)|sigmask(SIGHUP));
+  do {
+    ppid = waitpid(pid, (int *) &pstat, 0);
+  } while (pid == -1 && errno == EINTR);
+  (void)sigsetmask(omask);
 }
 
 int kill_irrd (uii_connection_t *uii) {
