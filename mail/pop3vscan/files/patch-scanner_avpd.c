--- scanner_avpd.c.orig	Sun Jun 29 21:08:46 2003
+++ scanner_avpd.c	Sun Jun 29 21:10:12 2003
@@ -74,7 +74,7 @@
     if (avp_fd!=-1 && connected==-1){
 	do_log(LOG_DEBUG, "Trying to connect to socket");
 	if (connect(avp_fd, (struct sockaddr *)(&avp_socket),
-			sizeof(avp_socket.sun_family) + strlen(NodeCtl)) >= 0){
+			SUN_LEN(&avp_socket)) >= 0){
 	    connected=1;
 	    do_log(LOG_DEBUG, "avp_socket_connect connected to kavdaemon"); 
 	    return 0;
