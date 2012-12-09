--- src/LibsslTLSContext.cc.orig	2012-12-01 22:52:46.000000000 +0800
+++ src/LibsslTLSContext.cc	2012-12-09 00:35:46.456524052 +0800
@@ -57,8 +57,12 @@
                      ERR_error_string(ERR_get_error(), 0)));
   }
   // Disable SSLv2 and enable all workarounds for buggy servers
+  #ifdef SSL_OP_NO_COMPRESSION
   SSL_CTX_set_options(sslCtx_, SSL_OP_ALL|SSL_OP_NO_SSLv2|
                       SSL_OP_NO_COMPRESSION);
+  #else
+  SSL_CTX_set_options(sslCtx_, SSL_OP_ALL|SSL_OP_NO_SSLv2);
+  #endif
   SSL_CTX_set_mode(sslCtx_, SSL_MODE_AUTO_RETRY);
   SSL_CTX_set_mode(sslCtx_, SSL_MODE_ENABLE_PARTIAL_WRITE);
   #ifdef SSL_MODE_RELEASE_BUFFERS
