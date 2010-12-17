--- lib/fetion_connection.c.orig	2010-11-28 20:53:01.000000000 +0900
+++ lib/fetion_connection.c	2010-12-12 11:56:42.000000000 +0900
@@ -22,6 +22,7 @@
 #include <fcntl.h>
 #include <sys/ioctl.h>
 #include <sys/types.h>
+#include <sys/socket.h>
 #include <netinet/in.h>
 #include <netinet/tcp.h>
 #include <arpa/inet.h>
@@ -34,9 +35,15 @@
 int tcp_keep_alive(int socketfd)
 {
 	int keepAlive = 1;
+#ifdef TCP_KEEPIDEL
 	int keepIdle = 10;
+#endif
+#ifdef TCP_KEEPINTVL
 	int keepInterval = 10;
+#endif
+#ifdef TCP_KEEPCNT
 	int keepCount = 10;
+#endif
 
 	if(setsockopt(socketfd , SOL_SOCKET , SO_KEEPALIVE 
 				,(void*)&keepAlive,sizeof(keepAlive)) == -1){
@@ -44,23 +51,29 @@
 		return -1;
 	}
 
+#ifdef TCP_KEEPIDEL
 	if(setsockopt(socketfd , SOL_TCP , TCP_KEEPIDLE 
 				,(void *)&keepIdle,sizeof(keepIdle)) == -1){
 		debug_info("set TCP_KEEPIDEL failed\n");
 		return -1;
 	}
+#endif
 
+#ifdef TCP_KEEPINTVL
 	if(setsockopt(socketfd , SOL_TCP , TCP_KEEPINTVL
 				,(void *)&keepInterval,sizeof(keepInterval)) == -1){
 		debug_info("set TCP_KEEPINTVL failed\n");
 		return -1;
 	}
+#endif
 
+#ifdef TCP_KEEPCNF
 	if(setsockopt(socketfd , SOL_TCP , TCP_KEEPCNT
 				,(void *)&keepCount,sizeof(keepCount)) == -1){
 		debug_info("set TCP_KEEPCNT failed\n");
 		return -1;
 	}
+#endif
 	return 1;
 }
 
@@ -369,10 +382,16 @@
 		c = tcp_connection_recv(conn , buf , sizeof(buf) - 1);
 		if(c <= 0)
 			break;
-		strcpy(res + n, buf);
 		n += c;
-		if(n >= len)
+		if(n > len){
+			free(res);
+			res = NULL;
 			break;
+		}
+		strcpy(res + n -c, buf);
+		if(n == len){
+			break;
+		}
 	}
 
 	return res;
