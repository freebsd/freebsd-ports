
$FreeBSD$

--- ehntserv.c.orig	Thu Oct  4 22:18:29 2001
+++ ehntserv.c	Fri May 30 14:16:22 2003
@@ -33,8 +33,8 @@
 #define MAXCLIENTS 256
 #define MAXPACKET 8192
 
-int SetUDPOpts(int);
-int SetTCPOpts(int);
+int SetUDPOpts(int, int);
+int SetTCPOpts(int, int);
 
 int debug;
 int use_syslog;
@@ -54,6 +54,8 @@
  int packetcounter=0;
  extern char *optarg;
  int c_udpport, c_tcpport;
+ int one = -1;
+ int bufsize = DEFAULT_SOCKBUF;
 
  debug=0;
  use_syslog=0;
@@ -61,7 +63,7 @@
  c_udpport=DEFAULT_UDP_PORT;
  c_tcpport=DEFAULT_TCP_PORT;
 
- while( (c=getopt(argc,argv,"u:t:d")) != -1) {
+ while( (c=getopt(argc,argv,"u:t:s:d")) != -1) {
 
    switch(c) {
    case 'u':
@@ -70,6 +72,13 @@
    case 't':
      sscanf(optarg,"%d",&c_tcpport);
      break;
+   case 's':
+     sscanf(optarg,"%d",&bufsize);
+     if (bufsize < MIN_SOCKBUF) {
+	     perror("too low buffer size or bad format: %s", optarg);
+	     exit(1);
+     }
+     break;
    case 'd':
      debug=1;
      break;
@@ -77,6 +86,7 @@
      printf("Usage: %s [ -u <udpport> ] [ -t <tcpport> ]\n",argv[0]);
      printf("  -u <udpport>  Listen on UDP port <udpport> for netflow packets.  Default %d\n",DEFAULT_UDP_PORT);
      printf("  -t <tcpport>  Listen on TCP port <tcpport> for client connections.  Default %d\n",DEFAULT_TCP_PORT);
+     printf("  -s <bufsize>  Set tcp/udp buffer size.  Default %d\n",DEFAULT_SOCKBUF);
      printf("  -d            Debug.  Don't become a daemon, displays all messages on stdout,");
      printf("                displays lots of extra information\n");
      exit(0);
@@ -87,22 +97,22 @@
 
  /* set up the netflow udp socket */
  if ( (nf_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
-   { log_error("socket (udp) error"); exit(0); }
+   { log_error("socket (udp) error"); exit(1); }
  memset(&nf_servaddr,0,sizeof(nf_servaddr));
  nf_servaddr.sin_family      = AF_INET;
  nf_servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  nf_servaddr.sin_port        = htons(c_udpport);
  if ( bind(nf_fd, (struct sockaddr *) &nf_servaddr, sizeof(nf_servaddr)) < 0)
-   { log_error("bind UDP error"); exit(0); }
+   { log_error("bind UDP error"); exit(1); }
 
- SetUDPOpts(nf_fd);
+ SetUDPOpts(nf_fd, bufsize);
 
  nf_clilen = (socklen_t) sizeof(nf_cliaddr);
  l_clilen = (socklen_t) sizeof(l_cliaddr);
  
  /* set up the listening tcp socket*/
  if ( (l_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
-   { log_error("socket (tcp) error"); exit(0); }
+   { log_error("socket (tcp) error"); exit(1); }
  memset(&l_servaddr,0,sizeof(l_servaddr));
  l_servaddr.sin_family      = AF_INET;
  l_servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
@@ -112,9 +122,9 @@
   setsockopt(l_fd, SOL_SOCKET, SO_REUSEADDR, (void*)&one, sizeof(one));
  }
  if ( bind(l_fd,(struct sockaddr *) &l_servaddr, sizeof(l_servaddr)) < 0)
-   { log_error ("bind TCP error"); exit(0); }
+   { log_error ("bind TCP error"); exit(1); }
  if ( listen(l_fd, 32) < 0)
-   { log_error("listen error"); exit(0); }
+   { log_error("listen error"); exit(1); }
  printf("Listening on UDP port %d and TCP port %d (with a backlog of 32)\n",c_udpport,c_tcpport);
  memset(l_clients,0,sizeof(l_clients));
 
@@ -157,7 +167,7 @@
   }
 
   if ( (c=select(maxfd+1,&read_fds,NULL,NULL,NULL)) < 0)
-    { log_error("select (read) error"); exit(0); }
+    { log_error("select (read) error"); exit(1); }
   
   if (FD_ISSET(nf_fd,&read_fds)) {  /*a netflow message is waiting*/
 
@@ -168,7 +178,7 @@
     /* new packet */
     if ( (nf_rcount=recvfrom(nf_fd,(char *)(nf_packet + sizeof(nf_cliaddr.sin_addr.s_addr)),
 			     MAXPACKET,0,(struct sockaddr *)&nf_cliaddr,&nf_clilen)) < 0)
-      { log_error("recvfrom error"); exit(0); }
+      { log_error("recvfrom error"); exit(1); }
     
     /* Here we use a non-blocking select to find out which tcp clients we 
        can write to.  This ensures the write won't block, which would of course
@@ -189,7 +199,7 @@
     timeout.tv_sec=0;
     timeout.tv_usec=0;
     if ( (c=select(maxfd+1,NULL,&write_fds,NULL,&timeout)) < 0)
-      { log_error("select (write) error"); exit(0); }
+      { log_error("select (write) error"); exit(1); }
     for (i=0; i<MAXCLIENTS; i++) {
       if (l_clients[i] > 0) {
 	if (FD_ISSET(l_clients[i],&write_fds)) {
@@ -215,14 +225,14 @@
   if (FD_ISSET(l_fd,&read_fds)) {   /*we have a new TCP client*/
     int l_connfd,new_index=-1;
     socklen_t l_addrlen;
-    struct sockaddr * l_cliaddr;
+    struct sockaddr l_cliaddr;
 
     /*    printf("incoming connection on tcp 4444\n");*/
     l_addrlen=sizeof(l_cliaddr);
-    if ( (l_connfd = accept(l_fd,(struct sockaddr *) l_cliaddr, &l_addrlen)) < 0)
-      { log_error("accept error"); exit(0); }
+    if ( (l_connfd = accept(l_fd, &l_cliaddr, &l_addrlen)) < 0)
+      { log_error("accept error"); exit(1); }
 
-    SetTCPOpts(l_connfd);
+    SetTCPOpts(l_connfd, bufsize);
 
     for (i=0; i<MAXCLIENTS; i++) {
       if (l_clients[i]==0) {
@@ -268,25 +278,26 @@
 }
 
  /* Increase our receive buffer for nf_fd: */
-int SetUDPOpts(int fd){
-  int r,p,n;
+int SetUDPOpts(int fd, int rcvsize){
+  int r,p;
   socklen_t       optlen;
   
-  n=512*1024;
   optlen = sizeof(p);
   
   if (debug) {
     r=getsockopt(fd,SOL_SOCKET,SO_RCVBUF,&p,&optlen);
     printf("Before setsockopt, SO_RCVBUF is %d\n",p);
   }
-  r=setsockopt(fd,SOL_SOCKET,SO_RCVBUF,&n,sizeof(n));
+  if (setsockopt(fd,SOL_SOCKET,SO_RCVBUF,&rcvsize,sizeof(rcvsize)) < 0) {
+    perror("setsockopt SO_RCVBUF:");
+  }
   if (debug) {
     r=getsockopt(fd,SOL_SOCKET,SO_RCVBUF,&p,&optlen);
     printf("After setsockopt, SO_RCVBUF is %d\n",p);
   }
 }
 
-int SetTCPOpts(int fd) { 
+int SetTCPOpts(int fd, int bufsize) { 
   int r,p,n;
   socklen_t       optlen;
   
@@ -296,8 +307,7 @@
     r=getsockopt(fd,SOL_SOCKET,SO_SNDBUF,&p,&optlen);
     printf("Before setsockopt, SO_SNDBUF is %d\n",p);
   }
-  n=512*1024;
-  r=setsockopt(fd,SOL_SOCKET,SO_SNDBUF,&n,sizeof(n));
+  r=setsockopt(fd,SOL_SOCKET,SO_SNDBUF,&bufsize,sizeof(bufsize));
   if (r<0) { log_error("setsockopt SO_SNDBUF"); }
   if (debug) {
     r=getsockopt(fd,SOL_SOCKET,SO_SNDBUF,&p,&optlen);
