--- scanner_trophie.c.orig	Sun Jun 29 21:08:53 2003
+++ scanner_trophie.c	Sun Jun 29 21:10:34 2003
@@ -61,7 +61,7 @@
     if (trophie_fd!=-1 && connected==-1){
 	do_log(LOG_DEBUG, "Trying to connect to socket");
 	if (connect(trophie_fd, (struct sockaddr *)(&trophie_socket),
-			sizeof(trophie_socket.sun_family) + strlen(config->virusscanner)) >= 0){
+			SUN_LEN(&trophie_socket)) >= 0){
 	    connected=1;
 	    do_log(LOG_DEBUG, "trophie_socket_connect connected"); 
 	    return 0;
