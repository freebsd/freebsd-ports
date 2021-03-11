--- src/mail/ngx_mail_handler.c.orig	2021-03-10 10:39:31.807351000 -0500
+++ src/mail/ngx_mail_handler.c	2021-03-10 10:41:28.739497000 -0500
@@ -273,14 +273,15 @@
 ngx_mail_init_session_handler(ngx_event_t *rev)
 {
     ngx_connection_t    *c;
-    ngx_mail_session_t  *s;
 
     c = rev->data;
-    s = c->data;
 
 #if (NGX_MAIL_SSL)
     {
+    ngx_mail_session_t   *s;
     ngx_mail_ssl_conf_t  *sslcf;
+
+    s = c->data;
 
     sslcf = ngx_mail_get_module_srv_conf(s, ngx_mail_ssl_module);
 
