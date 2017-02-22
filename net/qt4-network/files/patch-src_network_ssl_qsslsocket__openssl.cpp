* Make availability of SSLv3 in Qt4 same as in Qt5, i.e. not part of SecureProtocols
*
--- src/network/ssl/qsslsocket_openssl.cpp.orig	2015-05-07 14:14:44 UTC
+++ src/network/ssl/qsslsocket_openssl.cpp
@@ -267,9 +267,13 @@ init_context:
 #endif
         break;
     case QSsl::SslV3:
+#ifndef OPENSSL_NO_SSL3_METHOD
         ctx = q_SSL_CTX_new(client ? q_SSLv3_client_method() : q_SSLv3_server_method());
+#else
+        ctx = 0; // SSL 3 not supported by the system, but chosen deliberately -> error
+#endif
         break;
-    case QSsl::SecureProtocols: // SslV2 will be disabled below
+    case QSsl::SecureProtocols: // SslV2/3 will be disabled below
     case QSsl::TlsV1SslV3: // SslV2 will be disabled below
     case QSsl::AnyProtocol:
     default:
@@ -297,8 +301,10 @@ init_context:
 
     // Enable bug workarounds.
     long options;
-    if (configuration.protocol == QSsl::TlsV1SslV3 || configuration.protocol == QSsl::SecureProtocols)
+    if (configuration.protocol == QSsl::TlsV1SslV3)
         options = SSL_OP_ALL|SSL_OP_NO_SSLv2;
+    else if (configuration.protocol == QSsl::SecureProtocols)
+        options = SSL_OP_ALL|SSL_OP_NO_SSLv2|SSL_OP_NO_SSLv3;
     else
         options = SSL_OP_ALL;
 
