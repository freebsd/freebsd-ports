--- src/tcp_sock.c	2006-04-19 12:13:21.000000000 -0800
+++ src/tcp_sock.c	2007-10-01 13:31:39.000000000 -0800
@@ -153,7 +153,6 @@
 void tcp_sockdcon(int sock_num)
 {
 	close((int) tcp_sock[sock_num]);
-	(int) tcp_sock[sock_num] = 0;
 }
 
 /* Read Data Function (Data IN)*/
Common subdirectories: src.orig/windows and src/windows
