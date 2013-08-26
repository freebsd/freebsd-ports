--- tls_remote.c.orig	2013-08-26 14:12:08.434131056 -0500
+++ tls_remote.c	2013-08-26 14:13:09.158131515 -0500
@@ -59,7 +59,7 @@
 int tls_checkcrl(SSL *ssl)
 {
 
-  return;
+  return 0;
 }
 
 int tls_exit(SSL *ssl)
