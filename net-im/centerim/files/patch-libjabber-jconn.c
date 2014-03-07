--- libjabber/jconn.c.orig	2011-05-23 01:06:31.000000000 +0400
+++ libjabber/jconn.c	2014-01-21 07:29:07.642848274 +0400
@@ -824,7 +824,7 @@
 		free(hash);
 		close(sock);
 		close(fd_file);
-		return;
+		return NULL;
 	}
 	 
 	recv( sock, buff, SEND_BUF, 0 );
@@ -833,7 +833,7 @@
 		free(hash);
 		close(sock);
 		close(fd_file);
-		return;
+		return NULL;
 	}
 	 
 //socks5 bytestream packet	 
@@ -851,7 +851,7 @@
 		free(hash);
 		close(sock);
 		close(fd_file);
-		return;
+		return NULL;
 	}
 	recv( sock, buff, 47, 0 );
 	if( buff[0] != 0x05 || buff[3] != 0x03 )
@@ -859,7 +859,7 @@
 		free(hash);
 		close(sock);
 		close(fd_file);
-		return;
+		return NULL;
 	}
 
 
@@ -889,6 +889,7 @@
 
 	 
 #endif
+	return NULL;
 }
  
 
@@ -961,5 +962,6 @@
  
 	pthread_exit(0);
 #endif
-	 
+
+	return NULL;
 }
