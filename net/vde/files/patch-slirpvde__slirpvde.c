--- slirpvde/slirpvde.c	Sat Jan 29 15:02:08 2005
+++ slirpvde/slirpvde.c	Sun Jan 30 14:24:33 2005
@@ -7,7 +7,9 @@
 #include <signal.h>
 #include <errno.h>
 #include <unistd.h>
+#ifndef __FreeBSD__
 #include <stdint.h>
+#endif
 #include <libgen.h>
 #include <sys/ioctl.h>
 #include <sys/socket.h>
@@ -16,6 +18,10 @@
 #include <sys/poll.h>
 #include <libslirp.h>
 #include <getopt.h>
+#ifdef __FreeBSD__
+#include <string.h>
+#include <sys/time.h>
+#endif
 
 #define SWITCH_MAGIC 0xfeedface
 #define BUFSIZE 2048
@@ -32,6 +38,25 @@
   struct sockaddr_un sock;
 };
 
+#ifdef __FreeBSD__
+#include "../vde.h"
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
+  fprintf(stderr, "Caught signal %d, cleaning up and exiting\n", sig);
+  cleanup(1,NULL);
+  signal(sig, SIG_DFL);
+  kill(getpid(), sig);
+}
+#endif
+
 static int send_fd(char *name, int fddata, struct sockaddr_un *datasock, int group)
 {
   int pid = getpid();
@@ -39,6 +64,9 @@
   int fdctl;
 
   struct sockaddr_un sock;
+#ifdef __FreeBSD__
+  struct timeval tv;
+#endif
 
   if((fdctl = socket(AF_UNIX, SOCK_STREAM, 0)) < 0){
     perror("socket");
@@ -58,7 +86,14 @@
   
   req.sock.sun_family=AF_UNIX;
   memset(req.sock.sun_path, 0, sizeof(req.sock.sun_path));
+#ifdef __FreeBSD__
+  gettimeofday(&tv, NULL);
+  snprintf(req.sock.sun_path, sizeof(req.sock.sun_path), "%s.%i.%li",
+          VDEDATSOCK, pid, tv.tv_usec);
+  data_socket = strdup(req.sock.sun_path);
+#else
   sprintf(&req.sock.sun_path[1], "%5d", pid);
+#endif
 
   if(bind(fddata, (struct sockaddr *) &req.sock, sizeof(req.sock)) < 0){
     perror("bind");
@@ -149,7 +184,6 @@
   int group=0;
   int connected_fd;
   register ssize_t nx;
-  register int i;
   fd_set rs,ws,xs;
   int opt,longindx;
   char *netw=NULL;
@@ -175,6 +209,12 @@
     exit(1);
   }
   connected_fd=send_fd(sockname, fddata, &dataout, group);
+#ifdef __FreeBSD__
+  if(signal(SIGINT, sig_handler) < 0) {
+        perror("signal");
+  }
+  signal(SIGPIPE, SIG_IGN); /* FreeBSD 4.x sends SIGPIPE on reset sockets */
+#endif
   slirp_init(netw);
 
   for(;;) {
