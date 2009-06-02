--- bounce.c.orig	2009-03-08 23:05:57.000000000 +0900
+++ bounce.c	2009-03-08 23:07:09.000000000 +0900
@@ -1,5 +1,7 @@
 /* socket bouncer, by orabidoo  12 Feb '95 
    using code from mark@cairo.anu.edu.au's general purpose telnet server.
+   Hacked by scot@poptart.org (April 1999) to allow a local bind address
+   and syslog logging.
 */
 
 #include <stdio.h>
@@ -20,13 +22,16 @@
 #include <sys/ioctl.h>
 #include <signal.h>
 #include <sys/wait.h>
+#include <unistd.h>
+#include <syslog.h>
+#include <stdlib.h>
+#include <string.h>
 
 #define    QLEN           5
 #define    DEFAULT_PORT   1523
 
 char sbuf[16384], cbuf[16384];
-extern int errno;
-extern char *sys_errlist[];
+int t=0;
 
 void sigchld() {
   signal(SIGCHLD, sigchld);
@@ -42,12 +47,15 @@
 
     struct itimerval itime;
 
+    if (t)
+    {
     itime.it_interval.tv_sec=0;
     itime.it_interval.tv_usec=0;
-    itime.it_value.tv_sec=21600;
+    itime.it_value.tv_sec=t;
     itime.it_value.tv_usec=0;
     setitimer(ITIMER_REAL,&itime,NULL);
     /* arbitrary connection time limit: 6 hours (in case the client hangs) */
+    }
 
     chead=ctail=cbuf;
     cpos=0;
@@ -134,31 +142,66 @@
 }
 
 int main(int argc,char *argv[]) {
-    int srv_fd, rem_fd, len, cl_fd, on=1;
+    int srv_fd, rem_fd, len, cl_fd, on=1, b=0, d=0, q=0;
     int myport=DEFAULT_PORT, remoteport;
-    struct sockaddr_in rem_addr, srv_addr, cl_addr;
+    struct sockaddr_in rem_addr, srv_addr, cl_addr, src_addr;
     char *myname;
-    struct hostent *hp;
+    struct hostent *hp, *hpLocal;
+
+    extern char *optarg;
+    extern int optind;
+    char *hostname = NULL;
+    char *sourcename = NULL;
+    char ch;
 
     myname=argv[0];
-    if (argc==5) {
-	if (strcmp(argv[1],"-p")==0) {
-	    if ((myport=atoi(argv[2]))==0) {
-		fprintf(stderr,"Bad port number.\n");
-		exit(-1);
-	    }
-	    argv+=2;
-	    argc-=2;
-	} else {
-	    fprintf(stderr,"Use: %s [-p localport] machine port \n",myname);
-	    exit(-1);
+
+    /* Process arguments */
+
+    while( (ch = getopt(argc, argv, "p:a:b:dqt:")) != -1  ) {
+      switch(ch) { 
+      case 'b': b = 1;
+	sourcename = malloc( strlen(optarg) + 1);
+	if( !sourcename ) {
+	  fprintf( stderr, "Can't allocate memory!\n" );
+	  exit(-1);
 	}
+	strcpy( sourcename, optarg );
+	break;
+      case 'a':
+	hostname = malloc( strlen(optarg) + 1);
+	if( !hostname ) {
+	  fprintf( stderr, "Can't allocate memory!\n" );
+	  exit(-1);
+	}
+	strcpy( hostname, optarg );
+	break;
+
+      case 'd': d = 1; break;
+      case 'q': q = 1; break;
+      case 'p':
+	if ((myport=atoi(optarg))==0) {
+	  fprintf(stderr,"Bad port number.\n");
+	  exit(-1);
+	}
+	break;
+      case 't':
+	if ((t=atoi(optarg)) == 0)  {
+	  fprintf(stderr, "Bad timer value.\n");
+	  exit(-1);
+	}
+	break;
+      }
     }
-    if (argc!=3) {
-	fprintf(stderr,"Use: %s [-p localport] machine port \n",myname);
+
+    argc -= optind;
+    argv += optind;
+
+    if (argc!=2) {
+	fprintf(stderr,"Use: %s [-a localaddr | -b localaddr] [-d] [-q] [-p localport] [-t timer] machine port \n",myname);
 	exit(-1);
     }
-    if ((remoteport=atoi(argv[2]))<=0) {
+    if ((remoteport=atoi(argv[1]))<=0) {
 	fprintf(stderr, "Bad remote port number.\n");
 	exit(-1);
     }
@@ -166,11 +209,12 @@
     memset((char *) &rem_addr, 0, sizeof(rem_addr));
     memset((char *) &srv_addr, 0, sizeof(srv_addr));
     memset((char *) &cl_addr, 0, sizeof(cl_addr));
+    memset((char *) &src_addr, 0, sizeof(src_addr));
 
     cl_addr.sin_family=AF_INET;
     cl_addr.sin_port=htons(remoteport);
-    if ((hp=gethostbyname(argv[1]))==NULL) {
-	cl_addr.sin_addr.s_addr=inet_addr(argv[1]);
+    if ((hp=gethostbyname(argv[0]))==NULL) {
+	cl_addr.sin_addr.s_addr=inet_addr(argv[0]);
 	if (cl_addr.sin_addr.s_addr==-1) {
 	    fprintf(stderr, "Unknown host.\n");
 	    exit(-1);
@@ -178,19 +222,43 @@
     } else
 	cl_addr.sin_addr=*(struct in_addr *)(hp->h_addr_list[0]);
 
+    if( hostname ) {
+      if ((hpLocal=gethostbyname(hostname))==NULL) {
+	srv_addr.sin_addr.s_addr=inet_addr(hostname);
+	if (srv_addr.sin_addr.s_addr==-1) {
+	    fprintf(stderr, "Unknown host: %s\n", hostname);
+	    exit(-1);
+	}
+    } else
+	srv_addr.sin_addr=*(struct in_addr *)(hp->h_addr_list[0]);
+    }
+
+    if( sourcename ) {
+      if ((hpLocal=gethostbyname(sourcename))==NULL) {
+	src_addr.sin_addr.s_addr=inet_addr(sourcename);
+	if (src_addr.sin_addr.s_addr==-1) {
+	    fprintf(stderr, "Unknown host: %s\n", sourcename);
+	    exit(-1);
+	}
+    } else
+        src_addr.sin_addr=*(struct in_addr *)(hp->h_addr_list[0]);
+    }
+    src_addr.sin_family=AF_INET;
+
     srv_addr.sin_family=AF_INET;
-    srv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
+    /*    srv_addr.sin_addr.s_addr=htonl(INADDR_ANY); */
     srv_addr.sin_port=htons(myport);
     srv_fd=socket(PF_INET,SOCK_STREAM,0);
-    if (bind(srv_fd,&srv_addr,sizeof(srv_addr))==-1) {
+    if (bind(srv_fd,(struct sockaddr *)&srv_addr,sizeof(srv_addr))==-1) {
 	perror("bind");
         exit(-1);
     }
     listen(srv_fd,QLEN);
+    srv_addr.sin_port=0;
 
     signal(SIGCHLD, sigchld);
     printf("Ready to bounce connections from port %i to %s on port %i\n",
-	   myport, argv[1], remoteport);
+	   myport, argv[0], remoteport);
     close(0); close(1); close(2);
     chdir("/");
 #ifdef TIOCNOTTY
@@ -202,11 +270,15 @@
     if (fork()) exit(0);
     while (1) {
 	len=sizeof(rem_addr);
-	rem_fd=accept(srv_fd,&rem_addr,&len);
+	rem_fd=accept(srv_fd,(struct sockaddr *)&rem_addr,&len);
 	if (rem_fd<0) {
 	  if (errno==EINTR) continue;
 	  exit(-1);
         }
+        if (!q) {
+		syslog( LOG_NOTICE, "connection from %s to local port %i.  Bouncing to %s, %i",
+			inet_ntoa(rem_addr.sin_addr), myport, argv[0], remoteport );
+	}
 	switch(fork()) {
 	  case -1:
 	    /* we're in the background.. no-one to complain to */
@@ -220,6 +292,17 @@
 		close(rem_fd);
 		exit(-1);
 	    }
+	    if (b) { src_addr.sin_port=0;
+	    if (bind(cl_fd,(struct sockaddr *)&src_addr,sizeof(src_addr))<0) {
+		close(rem_fd);
+		exit(-1);
+	    }
+	    }
+	    if (d) {
+	    if ((hp=gethostbyname(argv[0]))!=NULL) {
+		cl_addr.sin_addr=*(struct in_addr *)(hp->h_addr_list[0]);
+	    }
+	    }
 	    if (connect(cl_fd, (struct sockaddr *)&cl_addr, 
 	                sizeof(cl_addr))<0) {
 		close(rem_fd);
