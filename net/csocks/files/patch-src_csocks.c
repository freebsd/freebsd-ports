--- csocks.c.orig	2008-02-25 09:37:38.000000000 +0100
+++ csocks.c	2008-02-25 09:38:53.000000000 +0100
@@ -1537,11 +1537,7 @@
 		continue;
 	}while(1);
 
-#if defined(DARWIN) || defined(NETBSD)
 	if ((rlen = send (sock, (void *) sen, lenght, 0)) <= 0){
-#else
-	if ((rlen = send (sock, (void *) sen, lenght, MSG_NOSIGNAL)) <= 0){
-#endif
 		fprintf(stderr,"ERROR - socks_send - send - cannot send message!\n");
 		return CSOCKS_KO;
 	}
