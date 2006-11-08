diff -urN nbd-2.8.3.orig/nbd-server.c nbd-2.8.3/nbd-server.c
--- nbd-2.8.3.orig/nbd-server.c	Thu Dec 22 21:37:20 2005
+++ nbd-server.c	Sun Jan  8 16:45:30 2006
@@ -363,12 +363,12 @@
  * is severely wrong)
  **/
 void sigchld_handler(int s) {
-        int* status=NULL;
+        int status;
 	int* i;
 	pid_t pid;
 	int done=0;
 
-	while(!done && (pid=wait(status)) > 0) {
+	while(!done && (pid=wait(&status)) > 0) {
 		if(WIFEXITED(status)) {
 			msg3(LOG_INFO, "Child exited with %d", WEXITSTATUS(status));
 			msg3(LOG_INFO, "pid is %d", pid);
