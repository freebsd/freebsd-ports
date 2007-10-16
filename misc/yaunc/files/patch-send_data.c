--- send_data.c.orig	Fri Oct 12 15:36:52 2007
+++ send_data.c	Fri Oct 12 15:36:58 2007
@@ -30,7 +30,7 @@
 	memset(&servaddr, '0', sizeof(servaddr));
 	servaddr.sin_family = AF_INET;
 	servaddr.sin_port = htons(UPPORT);
-	Inet_pton(AF_INET, ip, &servaddr.sin_addr);
+	inet_pton(AF_INET, ip, &servaddr.sin_addr);
 	free(ip);
 
 	/* communicate via the socket, with the server */
