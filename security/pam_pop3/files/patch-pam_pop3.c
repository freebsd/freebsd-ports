--- pam_pop3.c.orig	Tue Jul 16 00:14:29 2002
+++ pam_pop3.c	Tue Jul 16 00:16:38 2002
@@ -21,6 +21,7 @@
 #include <errno.h>
 #include <netdb.h>
 #include <sys/types.h>
+#include <sys/time.h>
 #include <netinet/in.h>
 #include <sys/socket.h>
 
@@ -85,7 +86,7 @@
 		close(sockfd);
 		return -1;
 	}
-	if ((numbytes=recv(sockfd,buf,BUFLEN-1,MSG_NOSIGNAL))<=0)
+	if ((numbytes=recv(sockfd,buf,BUFLEN-1,0))<=0)
 	{
 		if (numbytes==0)
 	/* other side closed connection */
@@ -138,7 +139,7 @@
 		close(sockfd);
 		return -1;
 	}
-	if ((numbytes=send(sockfd,buf,strlen(buf),MSG_NOSIGNAL))<strlen(buf)) 
+	if ((numbytes=send(sockfd,buf,strlen(buf),0))<strlen(buf)) 
 	{
 /* it did not send everything, try once more and then fail */
 		if (numbytes>0)
@@ -153,7 +154,7 @@
 			return -1;
 		}
 			/* send remaining bytes */
-			numbytes+=send(sockfd,buf+numbytes,strlen(buf)-numbytes,MSG_NOSIGNAL);
+			numbytes+=send(sockfd,buf+numbytes,strlen(buf)-numbytes,0);
 		}
 		if (numbytes!=strlen(buf))
 		{
