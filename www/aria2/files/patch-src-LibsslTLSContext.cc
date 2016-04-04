--- src/LibsslTLSContext.cc.orig	2015-02-23 14:34:01 UTC
+++ src/LibsslTLSContext.cc
@@ -112,14 +112,20 @@ OpenSSLTLSContext::OpenSSLTLSContext(TLS
 
   long ver_opts = 0;
   switch (minVer) {
+#ifdef SSL_OP_NO_TLSv1_1
   case TLS_PROTO_TLS12:
     ver_opts |= SSL_OP_NO_TLSv1_1;
+#endif // SSL_OP_NO_TLSv1_1
   // fall through
+#ifdef SSL_OP_NO_TLSv1
   case TLS_PROTO_TLS11:
     ver_opts |= SSL_OP_NO_TLSv1;
+#endif // SSL_OP_NO_TLSv1
   // fall through
+#ifdef SSL_OP_NO_SSLv3
   case TLS_PROTO_TLS10:
     ver_opts |= SSL_OP_NO_SSLv3;
+#endif // SSL_OP_NO_SSLv3
   default:
     break;
   };
