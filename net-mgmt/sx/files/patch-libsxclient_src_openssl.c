--- libsxclient/src/openssl.c.orig	2015-07-24 14:26:43 UTC
+++ libsxclient/src/openssl.c
@@ -98,6 +98,8 @@ int sxi_sslctxfun(sxc_client_t *sx, curl
         return -1;
     }
     SSL_CTX *ctx = (SSL_CTX*)info->internals;
+    if (!ctx)
+        return -EAGAIN;
     SSL_CTX_set_cert_verify_callback(ctx, ssl_verify_hostname, ev);
     return 0;
 }
