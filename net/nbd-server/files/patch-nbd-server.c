diff -urN nbd-2.8.2.orig/nbd-server.c nbd-2.8.2/nbd-server.c
--- nbd-2.8.2.orig/nbd-server.c	Wed Nov  9 22:38:44 2005
+++ nbd-server.c	Thu Dec 22 16:04:47 2005
@@ -363,11 +363,11 @@
  * is severely wrong)
  **/
 void sigchld_handler(int s) {
-        int* status=NULL;
+        int status;
 	int* i;
 	pid_t pid;
 
-	while((pid=wait(status)) > 0) {
+	while ((pid = waitpid(-1, &status, WNOHANG)) > 0) {
 		if(WIFEXITED(status)) {
 			msg3(LOG_INFO, "Child exited with %d", WEXITSTATUS(status));
 		}
@@ -684,7 +684,7 @@
 
 		if (request.magic != htonl(NBD_REQUEST_MAGIC))
 			err("Not enough magic.");
-		if (len > BUFSIZE)
+		if (len > (BUFSIZE-sizeof(struct nbd_reply)))
 			err("Request too big!");
 #ifdef DODBG
 		printf("%s from %Lu (%Lu) len %d, ", request.type ? "WRITE" :
