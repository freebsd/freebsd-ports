--- dissipate2/udpmessagesocket.cpp.orig	Mon Jul  5 13:51:09 2004
+++ dissipate2/udpmessagesocket.cpp	Mon Jul  5 13:59:32 2004
@@ -1,5 +1,7 @@
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
+#include <netinet/in_systm.h>
 #include <netinet/ip.h>
 #include <errno.h>
 #include <string.h>
@@ -52,7 +54,7 @@
 	socklen_t optlen;
 	tos=IPTOS_PREC_CRITIC_ECP;
 	optlen=1;
-	if(setsockopt(socketfd,SOL_IP,IP_TOS,&tos,optlen) != 0){
+	if(setsockopt(socketfd,IPPROTO_IP,IP_TOS,&tos,optlen) != 0){
 		perror("UDPMessageSocket::SetTOS");
 	}
 	return 0;
