--- tcpstuff.c.orig	2016-06-20 15:23:56 UTC
+++ tcpstuff.c
@@ -229,6 +229,7 @@ make_tcp_listener(unsigned short localpo
 
 
 /* this function takes in a listenFd and returns an acceptedFd */
+/* This is not used and gives a security warning in FreeBSD ports
 int
 tcp_accept(int listenFd)
 {
@@ -242,12 +243,14 @@ tcp_accept(int listenFd)
 			 (struct sockaddr *)&clientAddr,
 			 &addrLen)) < 0)
     {
+*/
       /* This is always an error, looping or not */
+/*
       return -1;
     }
-  
+*/  
   /* Set the "don't linger on close" option */
-  
+/*  
   lingerVal.l_onoff = 0;
   lingerVal.l_linger = 0;
   if (setsockopt(clientFd, SOL_SOCKET, SO_LINGER,
@@ -260,3 +263,4 @@ tcp_accept(int listenFd)
   return(clientFd);
   
 }
+*/
