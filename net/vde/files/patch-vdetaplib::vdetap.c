--- vdetaplib/vdetap.c	Sat Jan 29 15:02:08 2005
+++ vdetaplib/vdetap.c	Sun Jan 30 14:05:26 2005
@@ -2,11 +2,25 @@
  * Reseased under the GPLv2 */
 
 #include <stdio.h>
+#ifndef __FreeBSD__
 #include <stdint.h>
+#endif
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#include <sys/time.h>
+#include <unistd.h>
+#else
 #include <sys/select.h>
+#endif
 #include <sys/poll.h>
 #include <sys/socket.h>
 #include <sys/un.h>
+#ifdef __FreeBSD__
+#include "../vde.h"
+#include <signal.h>
+#include <stdlib.h>
+#include <string.h>
+#endif
 
 #define SWITCH_MAGIC 0xfeedface
 #define BUFSIZE 2048
@@ -21,6 +35,23 @@
 
 static unsigned char bufin[BUFSIZE];
 
+#ifdef __FreeBSD__
+static char *data_socket = NULL;
+
+static void cleanup()
+{
+    if(data_socket != NULL)
+        unlink(data_socket);
+}
+
+static void sig_handler(int sig)
+{
+    cleanup(1, NULL);
+    signal(sig, SIG_DFL);
+    kill(getpid(), sig);
+}
+#endif
+
 static int send_fd(char *name, int fddata, struct sockaddr_un *datasock, int intno, int group)
 {
 	int pid = getpid();
@@ -28,6 +59,9 @@
 	int fdctl;
 
 	struct sockaddr_un sock;
+#ifdef __FreeBSD__
+  struct timeval tv;
+#endif
 
 	if((fdctl = socket(AF_UNIX, SOCK_STREAM, 0)) < 0){
 		perror("socket");
@@ -47,7 +81,14 @@
 
 	req.sock.sun_family=AF_UNIX;
 	memset(req.sock.sun_path, 0, sizeof(req.sock.sun_path));
+#ifdef __FreeBSD__
+	gettimeofday(&tv, NULL);
+	snprintf(req.sock.sun_path, sizeof(req.sock.sun_path), "%s.%i.%li",
+	    VDEDATSOCK, pid, tv.tv_usec);
+	data_socket = strdup(req.sock.sun_path);
+#else
 	sprintf(&req.sock.sun_path[1], "%5d-%2d", pid, intno);
+#endif
 
 	if(bind(fddata, (struct sockaddr *) &req.sock, sizeof(req.sock)) < 0){
 		perror("bind");
@@ -69,7 +110,7 @@
 
 static struct pollfd pollv[]={{0,POLLIN|POLLHUP,0},{0,POLLIN|POLLHUP,0}};
 
-main(int argc,char *argv[])
+int main(int argc,char *argv[])
 {
 	int fd,fddata;
 	struct sockaddr_un dataout,datain;
@@ -96,6 +137,12 @@
 	send_fd(argv[2],fddata,&dataout,0,0);
 	pollv[0].fd=fd;
 	pollv[1].fd=fddata;
+
+#ifdef __FreeBSD__
+	if(signal(SIGINT, sig_handler) < 0) {
+		perror("signal");
+	}
+#endif
 	for(;;) {
 		result=poll(pollv,2,-1);
 		if (pollv[0].revents & POLLHUP || pollv[1].revents & POLLHUP)
@@ -113,5 +160,7 @@
 			write(fd,bufin,nx);
 		}
 	}
+	cleanup(0, NULL);
+	return 0;
 }
 
