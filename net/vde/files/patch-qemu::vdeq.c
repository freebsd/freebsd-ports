--- qemu/vdeq.c	Sat Jan 29 15:02:08 2005
+++ qemu/vdeq.c	Sun Jan 30 13:31:46 2005
@@ -7,14 +7,20 @@
 #include <signal.h>
 #include <errno.h>
 #include <unistd.h>
+#ifndef __FreeBSD__
 #include <stdint.h>
+#endif
 #include <libgen.h>
 #include <sys/ioctl.h>
 #include <sys/socket.h>
 #include <sys/un.h>
 #include <sys/uio.h>
 #include <sys/poll.h>
+#ifdef __FreeBSD__
+#include <string.h>
+#include <sys/time.h>
 #include "../vde.h"
+#endif
 
 #define SWITCH_MAGIC 0xfeedface
 #define BUFSIZE 2048
@@ -29,6 +35,15 @@
   struct sockaddr_un sock;
 };
 
+#ifdef __FreeBSD__
+static char *data_socket = NULL;
+
+static void cleanup()
+{
+    if(data_socket != NULL)
+        unlink(data_socket);
+}
+#endif
 
 static int send_fd(char *name, int fddata, struct sockaddr_un *datasock, int intno, int group)
 {
@@ -37,6 +52,9 @@
   int fdctl;
 
   struct sockaddr_un sock;
+#ifdef __FreeBSD__
+  struct timeval tv;
+#endif
 
   if((fdctl = socket(AF_UNIX, SOCK_STREAM, 0)) < 0){
     perror("socket");
@@ -56,7 +74,14 @@
   
   req.sock.sun_family=AF_UNIX;
   memset(req.sock.sun_path, 0, sizeof(req.sock.sun_path));
+#ifdef __FreeBSD__
+  gettimeofday(&tv, NULL);
+  snprintf(req.sock.sun_path, sizeof(req.sock.sun_path), "%s.%i.%li",
+          VDEDATSOCK, pid, tv.tv_usec);
+  data_socket = strdup(req.sock.sun_path);
+#else
   sprintf(&req.sock.sun_path[1], "%5d-%2d", pid, intno);
+#endif
 
   if(bind(fddata, (struct sockaddr *) &req.sock, sizeof(req.sock)) < 0){
     perror("bind");
@@ -111,20 +136,23 @@
 static void leave()
 {
 	fprintf(stderr,"qemu exited: %s quits\n", vdeqname);
+#ifdef __FreeBSD__
+	cleanup(0, NULL);
+#endif
 	exit(0);
 }
 
 int main(int argc, char **argv)
 {
   int *fddata;
-  char *argsock,**sockname;
+  char *argsock = NULL,**sockname;
   struct sockaddr_un *dataout,datain;
   int datainsize;
   int result;
   int group=0;
   int *connected_fd;
   register ssize_t nx;
-  int args;
+  int args = 0;
   int newargc;
   char **newargv;
   typedef int pair[2];
@@ -154,10 +182,10 @@
 		  )) {
 	  usage();
   } else if (argc > args+1 && 
-		  (strcmp(argv[args],"-vdesock")==0) ||
+		  ((strcmp(argv[args],"-vdesock")==0) ||
 		  (strcmp(argv[args],"-sock")==0) ||
 		  (strcmp(argv[args],"-unix")==0) ||
-		  (strcmp(argv[args],"-s")==0)
+		  (strcmp(argv[args],"-s")==0))
 	    ){
 	  argsock=argv[args+1];
 	  args+=2;
