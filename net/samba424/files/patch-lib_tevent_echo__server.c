--- lib/tevent/echo_server.c.orig	2026-01-20 15:42:54 UTC
+++ lib/tevent/echo_server.c
@@ -633,7 +633,7 @@ int main(int argc, const char **argv)
 		exit(1);
 	}
 
-	ret = listen(listen_sock, 5);
+	ret = listen(listen_sock, DEFAULT_LISTEN_BACKLOG);
 	if (ret == -1) {
 		perror("listen() failed");
 		exit(1);
