--- src/ssl.c.orig	2009-05-09 19:11:47.000000000 +0400
+++ src/ssl.c	2009-07-16 21:44:52.000000000 +0400
@@ -67,6 +67,7 @@
   if (ssl->state == ST_SSL_CLOSED)
     return IO_CLOSED;
   for ( ; ; ) {
+    ERR_clear_error();
     int err = SSL_do_handshake(ssl->ssl);
     ssl->error = SSL_get_error(ssl->ssl, err);
     switch(ssl->error) {
@@ -109,6 +110,7 @@
     return IO_CLOSED;
   *sent = 0;
   for ( ; ; ) {
+    ERR_clear_error();
     int err = SSL_write(ssl->ssl, data, (int) count);
     ssl->error = SSL_get_error(ssl->ssl, err);
     switch(ssl->error) {
@@ -151,6 +153,7 @@
     return IO_CLOSED;
   *got = 0;
   for ( ; ; ) {
+    ERR_clear_error();
     int err = SSL_read(ssl->ssl, data, (int) count);
     ssl->error = SSL_get_error(ssl->ssl, err);
     switch(ssl->error) {
