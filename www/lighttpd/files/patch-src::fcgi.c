--- src/fcgi.c.orig	Sun Feb  6 11:17:21 2005
+++ src/fcgi.c	Sun Feb  6 11:17:43 2005
@@ -1691,7 +1691,7 @@
 	
 #ifdef USE_OPENSSL
 	if (srv_sock->is_ssl) {
-		fcgi_env_add(p->fcgi_env, CONST_STR_LEN("HTTPS"), "on");
+		fcgi_env_add(p->fcgi_env, CONST_STR_LEN("HTTPS"), CONST_STR_LEN("on"));
 	}
 #endif
