#
# http://trac.lighttpd.net/trac/ticket/861
#
--- src/mod_cgi.c.orig	Mon Mar 26 09:25:21 2007
+++ src/mod_cgi.c	Mon Mar 26 09:27:23 2007
@@ -842,6 +842,12 @@
 				    CONST_BUF_LEN(con->authed_user));
 		}
 
+#ifdef USE_OPENSSL
+		if (srv_sock->is_ssl) {
+			cgi_env_add(&env, CONST_STR_LEN("HTTPS"), CONST_STR_LEN("on"));
+		}
+#endif
+
 		/* request.content_length < SSIZE_MAX, see request.c */
 		ltostr(buf, con->request.content_length);
 		cgi_env_add(&env, CONST_STR_LEN("CONTENT_LENGTH"), buf, strlen(buf));
