--- ssl/ssldecode.c.orig	Sat Aug 17 05:33:17 2002
+++ ssl/ssldecode.c	Fri Jan 20 13:09:49 2006
@@ -51,6 +51,7 @@
 #include <openssl/ssl.h>
 #include <openssl/hmac.h>
 #include <openssl/evp.h>
+#include <openssl/md5.h>
 #include <openssl/x509v3.h>
 #endif
 #include "ssldecode.h"
@@ -131,7 +132,8 @@
     ssl_decode_ctx *d=0;
     int r,_status;
     
-    SSLeay_add_all_algorithms();
+    SSL_library_init();
+    OpenSSL_add_all_algorithms();
     if(!(d=(ssl_decode_ctx *)malloc(sizeof(ssl_decode_ctx))))
       ABORT(R_NO_MEMORY);
     if(!(d->ssl_ctx=SSL_CTX_new(SSLv23_server_method())))
