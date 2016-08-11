--- ../nginx-clojure-0.4.4/src/c/ngx_http_clojure_socket.c.orig	2016-05-24 17:39:48.898351000 -0400
+++ ../nginx-clojure-0.4.4/src/c/ngx_http_clojure_socket.c	2016-05-25 19:23:44.584704000 -0400
@@ -317,7 +317,7 @@
 	}
 	u->resolved->host.data = url->host.data;
 	u->resolved->host.len = url->host.len;
-	ngx_http_clojure_socket_upstream_connect(u, (struct sockaddr *)url->sockaddr, url->socklen);
+	ngx_http_clojure_socket_upstream_connect(u, &url->sockaddr, url->socklen);
 }
 
 static void ngx_http_clojure_socket_upstream_connect_inner(ngx_http_clojure_socket_upstream_t *u) {
