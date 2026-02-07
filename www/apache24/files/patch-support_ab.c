--- support/ab.c.orig	2017-05-28 21:15:41 UTC
+++ support/ab.c
@@ -197,6 +197,14 @@ typedef STACK_OF(X509) X509_STACK_TYPE;
 #if !defined(OPENSSL_NO_TLSEXT) && defined(SSL_set_tlsext_host_name)
 #define HAVE_TLSEXT
 #endif
+#if defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x2060000f
+# define SSL_CTRL_SET_MIN_PROTO_VERSION	123
+# define SSL_CTRL_SET_MAX_PROTO_VERSION 124
+#define SSL_CTX_set_min_proto_version(ctx, version) \
+   SSL_CTX_ctrl(ctx, SSL_CTRL_SET_MIN_PROTO_VERSION, version, NULL)
+#define SSL_CTX_set_max_proto_version(ctx, version) \
+   SSL_CTX_ctrl(ctx, SSL_CTRL_SET_MAX_PROTO_VERSION, version, NULL)
+#endif
 #endif
 
 #include <math.h>
