From: Jeremy Harris <jgh146exb@wizmail.org>
Date: Mon, 16 Apr 2018 17:45:04 +0000 (+0100)
Subject: Fix OpenSSL non-OCSP build
X-Git-Url: https://git.exim.org/exim.git/commitdiff_plain/37f0ce65959019e417ff79b9d0959e13470c5290

Fix OpenSSL non-OCSP build
---

diff --git a/src/src/tls-openssl.c b/src/src/tls-openssl.c
index fb59217..cefa94f 100644
--- src/tls-openssl.c.orig
+++ src/tls-openssl.c
@@ -2505,10 +2505,12 @@ if (error == SSL_ERROR_ZERO_RETURN)
   if (SSL_get_shutdown(server_ssl) == SSL_RECEIVED_SHUTDOWN)
  	SSL_shutdown(server_ssl);
 
+#ifndef DISABLE_OCSP
   sk_X509_pop_free(server_static_cbinfo->verify_stack, X509_free);
+  server_static_cbinfo->verify_stack = NULL;
+#endif
   SSL_free(server_ssl);
   SSL_CTX_free(server_ctx);
-  server_static_cbinfo->verify_stack = NULL;
   server_ctx = NULL;
   server_ssl = NULL;
   tls_in.active = -1;
@@ -2782,11 +2784,13 @@ if (shutdown)
     }
   }
 
+#ifndef DISABLE_OCSP
 if (is_server)
   {
   sk_X509_pop_free(server_static_cbinfo->verify_stack, X509_free);
   server_static_cbinfo->verify_stack = NULL;
   }
+#endif
 
 SSL_CTX_free(*ctxp);
 SSL_free(*sslp);
