--- lib/nsock.c.orig	2014-08-12 15:00:01 UTC
+++ lib/nsock.c
@@ -81,7 +81,7 @@ int nsock_unix(const char *path, unsigne
 	if(flags & NSOCK_UDP)
 		return sock;
 
-	if(listen(sock, 3) < 0) {
+	if(listen(sock, 48) < 0) {
 		close(sock);
 		return NSOCK_ELISTEN;
 	}
