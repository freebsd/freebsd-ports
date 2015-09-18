--- src/network/ssl/qsslsocket_openssl.cpp.orig	2015-05-07 14:14:44 UTC
+++ src/network/ssl/qsslsocket_openssl.cpp
@@ -269,13 +269,12 @@ init_context:
     case QSsl::SslV3:
         ctx = q_SSL_CTX_new(client ? q_SSLv3_client_method() : q_SSLv3_server_method());
         break;
-    case QSsl::SecureProtocols: // SslV2 will be disabled below
-    case QSsl::TlsV1SslV3: // SslV2 will be disabled below
     case QSsl::AnyProtocol:
-    default:
         ctx = q_SSL_CTX_new(client ? q_SSLv23_client_method() : q_SSLv23_server_method());
         break;
     case QSsl::TlsV1:
+    case QSsl::SecureProtocols:
+    default:
         ctx = q_SSL_CTX_new(client ? q_TLSv1_client_method() : q_TLSv1_server_method());
         break;
     }
