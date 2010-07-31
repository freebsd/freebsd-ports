--- ./mssl.c.orig	2010-07-31 15:40:14.760757000 +0200
+++ ./mssl.c	2010-07-31 15:40:31.439062000 +0200
@@ -28,6 +28,17 @@
 extern char last_error[];
 BIO *bio_err=0;
 
+char * strndup(const char *str, size_t len){
+        size_t l=strlen(str);
+        char *r;
+        if(len<l){
+                l=len;
+        }
+        r=malloc(l);
+        memcpy(r, str, l);
+        return r;
+}
+
 char close_ssl_connection(SSL *ssl_h, int socket_h)
 {
 	int rc = SSL_shutdown(ssl_h);
