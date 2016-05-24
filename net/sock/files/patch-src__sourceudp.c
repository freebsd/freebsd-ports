--- src/sourceudp.c.orig	2010-05-28 00:03:25 UTC
+++ src/sourceudp.c
@@ -29,28 +29,41 @@ source_udp(int sockfd)	/* TODO: use send
 		if (connectudp) {
 			if ( (n = write(sockfd, wbuf, writelen)) != writelen) {
 				if (ignorewerr) {
-					err_ret("write returned %d, expected %d", n, writelen);
-						/* also call getsockopt() to clear so_error */
+					err_ret("write returned %d, expected %d",
+					    n, writelen);
+					/* also call getsockopt() to clear so_error */
 					optlen = sizeof(option);
-       				if (getsockopt(sockfd, SOL_SOCKET, SO_ERROR,
-												&option, &optlen) < 0)
-           				err_sys("SO_ERROR getsockopt error");
-				} else
-					err_sys("write returned %d, expected %d", n, writelen);
+					if (getsockopt(sockfd, SOL_SOCKET,
+					    SO_ERROR, &option, &optlen) < 0)
+						err_sys("SO_ERROR getsockopt error");
+				} else {
+					err_sys("write returned %d, expected %d",
+					    n, writelen);
+				}
 			}
 		} else {
-		  if ( (n = sendto(sockfd, wbuf, writelen, 0,
-				   (struct sockaddr *) &servaddr,
-				   sizeof(struct sockaddr))) != writelen) {
-		    if (ignorewerr) {
-					err_ret("sendto returned %d, expected %d", n, writelen);
-						/* also call getsockopt() to clear so_error */
+			if (af_46 == AF_INET) {
+				n = sendto(sockfd, wbuf, writelen, 0,
+				   (struct sockaddr *) &servaddr4,
+				   sizeof(servaddr4));
+			} else {
+				n = sendto(sockfd, wbuf, writelen, 0,
+				   (struct sockaddr *) &servaddr6,
+				   sizeof(servaddr6));
+			}
+			if (n != writelen) {
+				if (ignorewerr) {
+					err_ret("sendto returned %d, expected %d",
+					    n, writelen);
+					/* also call getsockopt() to clear so_error */
 					optlen = sizeof(option);
-       				if (getsockopt(sockfd, SOL_SOCKET, SO_ERROR,
-												&option, &optlen) < 0)
-           				err_sys("SO_ERROR getsockopt error");
-				} else
-					err_sys("sendto returned %d, expected %d", n, writelen);
+					if (getsockopt(sockfd, SOL_SOCKET,
+					    SO_ERROR, &option, &optlen) < 0)
+						err_sys("SO_ERROR getsockopt error");
+				} else {
+					err_sys("sendto returned %d, expected %d",
+					    n, writelen);
+				}
 			}
 		}
 
