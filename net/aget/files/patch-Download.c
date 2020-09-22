--- Download.c.orig	2009-05-12 05:30:23 UTC
+++ Download.c
@@ -107,7 +107,7 @@ void * http_get(void *arg) {
 	pthread_mutex_unlock(&bwritten_mutex);
 
 	while (td->offset < foffset) {
-		memset(rbuf, GETRECVSIZ, 0);
+	  memset(rbuf, 0, GETRECVSIZ);
 		dr = recv(sd, rbuf, GETRECVSIZ, 0);
 		if ((td->offset + dr) > foffset)
 			dw = pwrite(td->fd, rbuf, foffset - td->offset, td->offset);
