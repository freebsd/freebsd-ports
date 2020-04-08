--- programs/IRRd/uii_commands.c.orig	2015-04-03 11:26:26 UTC
+++ programs/IRRd/uii_commands.c
@@ -14,6 +14,8 @@
 #include <ctype.h>
 #include "irrd.h"
 
+#include <errno.h>
+
 #include <fcntl.h>
 #ifndef SETPGRP_VOID
 #endif
@@ -700,6 +702,10 @@ int uii_read_update_file (uii_connection_t *uii, char 
 
 void run_cmd (char *cmd, FILE **in, FILE **out) {
   int pin[2], pout[2];
+  int pid;
+  int omask, pstat;
+  pid_t ppid;
+  extern int errno;
 
   if (in != NULL)
     *in = NULL;
@@ -713,7 +719,9 @@ void run_cmd (char *cmd, FILE **in, FILE **out) {
   if (out != NULL)
     pipe (pout);
   
-  if (fork() == 0) { /* We're the child */
+/*  if (fork() == 0) { */
+  pid = fork();
+  if (pid == 0) { /* We're the child */
     if (in != NULL) {
       close (pin[1]);
       dup2  (pin[0], 0);
@@ -727,7 +735,7 @@ void run_cmd (char *cmd, FILE **in, FILE **out) {
       close (pout[1]);
     }
     
-    execl("/bin/sh", "sh", "-c", cmd, NULL);
+    execlp("/bin/sh", "sh", "-c", cmd, NULL);
     _exit(127);
   }
 
@@ -741,6 +749,12 @@ void run_cmd (char *cmd, FILE **in, FILE **out) {
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
