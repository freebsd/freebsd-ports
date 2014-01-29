--- ./main.c.orig	2000-08-15 22:07:25.000000000 +0000
+++ ./main.c	2014-01-27 21:40:18.000000000 +0000
@@ -938,7 +938,7 @@
 
 			case 'V' :
 				printf("\nThis is glimpse version %s, %s.\n\n", GLIMPSE_VERSION, GLIMPSE_DATE);
-				RETURNMAIN(0);
+				RETURNMAIN(1);
 
 			default :
 				if (isdigit(c)) quitwhile = ON;
@@ -1063,7 +1063,7 @@
 		clargc = 0;
 		clargv = NULL;
 		cli_len = sizeof(cli_addr);
-		if ((newsockfd = accept(sockfd, &cli_addr, &cli_len)) < 0) continue;
+		if ((newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &cli_len)) < 0) continue;
 		if (getreq(newsockfd, glimpse_reqbuf, &clstdin, &clstdout, &clstderr, &clargc, &clargv, &clpid) < 0) {
 			ret = -1;
 #if	DEBUG
