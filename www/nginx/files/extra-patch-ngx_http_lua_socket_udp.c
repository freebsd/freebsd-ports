--- ../lua-nginx-module-0.9.15/src/ngx_http_lua_socket_udp.c.orig	2015-04-21 21:18:31.080702000 +0300
+++ ../lua-nginx-module-0.9.15/src/ngx_http_lua_socket_udp.c	2015-04-21 21:18:47.449758000 +0300
@@ -1400,17 +1400,6 @@
 
     c->number = ngx_atomic_fetch_add(ngx_connection_counter, 1);
 
-#if (NGX_THREADS)
-
-    /* TODO: lock event when call completion handler */
-
-    rev->lock = &c->lock;
-    wev->lock = &c->lock;
-    rev->own_lock = &c->lock;
-    wev->own_lock = &c->lock;
-
-#endif
-
 #if (NGX_HTTP_LUA_HAVE_SO_PASSCRED)
     if (uc->sockaddr->sa_family == AF_UNIX) {
         struct sockaddr         addr;
