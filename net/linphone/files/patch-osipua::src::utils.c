--- osipua/src/utils.c.orig	Thu Oct 23 13:06:43 2003
+++ osipua/src/utils.c	Thu Oct 23 13:07:24 2003
@@ -382,6 +382,7 @@
 		abort();
 		return -1;
 	}
+	((struct sockaddr_in *)(res->ai_addr))->sin_port=htons(9999);
 	err=connect(sock,res->ai_addr,res->ai_addrlen);
 	if (err<0) {
 		osip_trace(OSIP_ERROR,("Error in connect: %s\n",strerror(errno)));
