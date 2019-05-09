--- pxyconn.c.orig	2019-05-08 11:38:14 UTC
+++ pxyconn.c
@@ -938,7 +938,7 @@ pxy_try_remove_sslproxy_header(pxy_conn_child_ctx_t *c
 	}
 }
 
-#ifdef __APPLE__
+#if defined(__FreeBSD__) || defined(__APPLE__)
 #define getdtablecount() 0
 
 /*
