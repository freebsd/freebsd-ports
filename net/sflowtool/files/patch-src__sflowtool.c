--- ./src/sflowtool.c.orig	2011-01-26 04:35:22.270624572 +0300
+++ ./src/sflowtool.c	2011-01-26 04:36:29.375609602 +0300
@@ -3238,14 +3238,14 @@
 static int openInputUDPSocket(u_int16_t port)
 {
   int soc;
-  struct sockaddr_in6 myaddr_in;
+  struct sockaddr_in myaddr_in;
   long save_fd;
 
   /* Create socket */
-  memset((char *)&myaddr_in, 0, sizeof(struct sockaddr_in6));
-  myaddr_in.sin6_family = AF_INET6;
-  //myaddr_in.sin_addr.s_addr = INADDR_ANY;
-  myaddr_in.sin6_port = htons(port);
+  memset((char *)&myaddr_in, 0, sizeof(struct sockaddr_in));
+  myaddr_in.sin_family = AF_INET;
+  myaddr_in.sin_addr.s_addr = INADDR_ANY;
+  myaddr_in.sin_port = htons(port);
 
   if ((soc = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1) {
     fprintf(stderr, "socket() failed, %s\n", strerror(errno));
@@ -3260,7 +3260,7 @@
 #endif /* WIN32 */
 
   /* Bind the socket */
-  if (bind(soc, (struct sockaddr *)&myaddr_in, sizeof(struct sockaddr_in6)) == -1) {
+  if (bind(soc, (struct sockaddr *)&myaddr_in, sizeof(struct sockaddr_in)) == -1) {
     fprintf(stderr, "bind() failed, port = %d : %s\n", port, strerror(errno));
     exit(-7);
   }
