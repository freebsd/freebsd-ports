--- src/posttls-finger/posttls-finger.c.orig	2019-02-12 13:17:45 UTC
+++ src/posttls-finger/posttls-finger.c
@@ -1673,7 +1673,8 @@ static int finger(STATE *state)
     return (0);
 }
 
-#if defined(USE_TLS) && OPENSSL_VERSION_NUMBER < 0x10100000L
+#if defined(USE_TLS) && \
+    ( OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER) )
 
 /* ssl_cleanup - free memory allocated in the OpenSSL library */
 
@@ -2156,7 +2157,8 @@ int     main(int argc, char *argv[])
     cleanup(&state);
 
     /* OpenSSL 1.1.0 and later (de)initialization is implicit */
-#if defined(USE_TLS) && OPENSSL_VERSION_NUMBER < 0x10100000L
+#if defined(USE_TLS) && \
+    ( OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER) )
     ssl_cleanup();
 #endif
 
