--- session.c.orig	Sat Apr  6 22:47:26 2002
+++ session.c	Sat Apr  6 22:47:42 2002
@@ -347,6 +347,7 @@
 
 	/* Initiation of the INET socket */
 
+	bzero(&inet_addr.sin_zero, sizeof(inet_addr.sin_zero));
 	inet_addr.sin_family	= AF_INET;
 	inet_addr.sin_port	= htons(port);
         Accept_inet_mbox_num = 0;
