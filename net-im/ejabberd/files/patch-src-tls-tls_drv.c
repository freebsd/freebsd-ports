--- tls/tls_drv.c	Sat Apr  9 23:47:56 2005
+++ tls/tls_drv.c	Sat Apr 23 19:28:48 2005
@@ -1,4 +1,4 @@
-/* $Id: tls_drv.c 305 2005-04-09 23:47:56Z aleksey $ */
+/* $Id: tls_drv.c 327 2005-04-24 12:09:47Z alexey $ */
 
 #include <stdio.h>
 #include <string.h>
@@ -80,8 +80,8 @@
 	 d->ctx = SSL_CTX_new(SSLv23_server_method());
 	 die_unless(d->ctx, "SSL_CTX_new failed");
 
-	 res = SSL_CTX_use_certificate_chain_file(d->ctx, buf);
-	 die_unless(res > 0, "ssl_ctx_use_certificate_chain_file failed");
+	 res = SSL_CTX_use_certificate_file(d->ctx, buf, SSL_FILETYPE_PEM);
+	 die_unless(res > 0, "SSL_CTX_use_certificate_file failed");
 
 	 res = SSL_CTX_use_PrivateKey_file(d->ctx, buf, SSL_FILETYPE_PEM);
 	 die_unless(res > 0, "SSL_CTX_use_PrivateKey_file failed");
