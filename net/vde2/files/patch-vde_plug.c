--- vde_plug.c	Sat Jan 29 15:02:08 2005
+++ vde_plug.c	Sun Jan 30 13:52:57 2005
@@ -7,7 +7,9 @@
 #include <signal.h>
 #include <errno.h>
 #include <unistd.h>
+#ifndef __FreeBSD__
 #include <stdint.h>
+#endif
 #include <getopt.h>
 #include <sys/ioctl.h>
 #include <sys/socket.h>
@@ -15,6 +17,11 @@
 #include <sys/uio.h>
 #include <sys/poll.h>
 #include <sys/utsname.h>
+#ifdef __FreeBSD__
+#include <sys/time.h>
+#include <netinet/in.h>
+#include <string.h>
+#endif
 #include "vde.h"
 #ifdef VDE_IP_LOG
 #define DO_SYSLOG
@@ -47,6 +54,24 @@
 static struct passwd *callerpwd;
 static char host[256];
 
+#ifdef __FreeBSD__
+static char *data_socket = NULL;
+
+static void cleanup()
+{
+    if(data_socket != NULL)
+	unlink(data_socket);
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
 void write_syslog_entry(char *message)
 {
 	char *ssh_client;
@@ -183,6 +208,9 @@
   int fdctl;
 
   struct sockaddr_un sock;
+#ifdef __FreeBSD__
+  struct timeval tv;
+#endif
 
   if((fdctl = socket(AF_UNIX, SOCK_STREAM, 0)) < 0){
     perror("socket");
@@ -202,7 +230,14 @@
   
   req.sock.sun_family=AF_UNIX;
   memset(req.sock.sun_path, 0, sizeof(req.sock.sun_path));
+#ifdef __FreeBSD__
+  gettimeofday(&tv, NULL);
+  snprintf(req.sock.sun_path, sizeof(req.sock.sun_path), "%s.%i.%li",
+	  VDEDATSOCK, pid, tv.tv_usec);
+  data_socket = strdup(req.sock.sun_path);
+#else
   sprintf(&req.sock.sun_path[1], "%5d", pid);
+#endif
 
   if(bind(fddata, (struct sockaddr *) &req.sock, sizeof(req.sock)) < 0){
     perror("bind");
@@ -309,6 +344,10 @@
   int connected_fd;
   register ssize_t nx;
 
+#ifdef __FreeBSD__
+  atexit(cleanup);
+#endif
+  
   uname(&me);
   if (argv[0][0] == '-')
 	  netusage(); //implies exit
@@ -383,6 +422,12 @@
   }
   connected_fd=send_fd(sockname, fddata, &dataout, group);
   pollv[1].fd=fddata;
+
+#ifdef __FreeBSD__
+  if(signal(SIGINT, sig_handler) < 0) {
+	perror("signal");
+  }
+#endif
 
   for(;;) {
 	  result=poll(pollv,2,-1);
