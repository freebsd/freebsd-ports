--- src/mail/ngx_mail_auth_http_module.c.orig	2021-03-09 12:50:37.389186000 -0500
+++ src/mail/ngx_mail_auth_http_module.c	2021-03-09 12:55:40.877872000 -0500
@@ -1135,10 +1135,10 @@
     size_t                     len;
     ngx_buf_t                 *b;
     ngx_str_t                  login, passwd;
+    ngx_connection_t          *c;
 #if (NGX_MAIL_SSL)
     ngx_str_t                  verify, subject, issuer, serial, fingerprint,
                                raw_cert, cert;
-    ngx_connection_t          *c;
     ngx_mail_ssl_conf_t       *sslcf;
 #endif
     ngx_mail_core_srv_conf_t  *cscf;
@@ -1151,9 +1151,10 @@
         return NULL;
     }
 
+    c = s->connection;
+
 #if (NGX_MAIL_SSL)
 
-    c = s->connection;
     sslcf = ngx_mail_get_module_srv_conf(s, ngx_mail_ssl_module);
 
     if (c->ssl && sslcf->verify) {
