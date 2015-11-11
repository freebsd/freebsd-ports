--- evhtp.h.orig	2015-10-29 19:51:50 UTC
+++ evhtp.h
@@ -1285,7 +1285,7 @@ EVHTP_EXPORT evhtp_connection_t *
 evhtp_connection_new(evbase_t * evbase, const char * addr, uint16_t port);
 
 #ifndef DISABLE_SSL
-evhtp_connection_t * evhtp_connection_ssl_new(evbase_t * evbase, const char * addr, uint16_t port, evhtp_ssl_ctx_t * ctx);
+EVHTP_EXPORT evhtp_connection_t * evhtp_connection_ssl_new(evbase_t * evbase, const char * addr, uint16_t port, evhtp_ssl_ctx_t * ctx);
 #endif
 
 
