--- ./execute.c.orig	Tue Apr  3 15:07:38 2007
+++ ./execute.c	Tue Apr  3 15:07:48 2007
@@ -16,7 +16,6 @@
 #include "msg.h"
 #include "main.h"
 
-static void program_signal();
 
 /* Returns errorlevel */
 static int run_parent(int fd_read_filename, int pid)
@@ -204,15 +203,3 @@
 {
 }
 
-static void program_signal()
-{
-  struct sigaction act;
-
-  act.sa_handler = sigchld_handler;
-  /* Reset the mask */
-  memset(&act.sa_mask,0,sizeof(act.sa_mask));
-  act.sa_flags = SA_NOCLDSTOP;
-  act.sa_restorer = NULL;
-
-  sigaction(SIGCHLD, &act, NULL);
-}
