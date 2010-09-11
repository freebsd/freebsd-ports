--- ./http.c.orig	2010-08-29 06:51:52.000000000 +0200
+++ ./http.c	2010-09-10 16:34:23.990426501 +0200
@@ -182,7 +182,7 @@
 	struct uwsgi_http_req *ur = (struct uwsgi_http_req *) u_h_r ;
 
 	int clientfd = ur->fd;
-	int uwsgi_fd;
+	int uwsgi_fd = 0;
 
 	int need_to_read = 1;
 	int state = uwsgi_http_method;
