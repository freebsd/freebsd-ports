* Make availability of SSLv3 in Qt4 same as in Qt5, i.e. not part of SecureProtocols
*
--- src/network/ssl/qsslsocket_openssl.cpp.orig	2015-05-07 14:14:44 UTC
+++ src/network/ssl/qsslsocket_openssl.cpp
@@ -222,8 +222,7 @@ QSslCipher QSslSocketBackendPrivate::QSslCipher_from_S
             ciph.d->encryptionMethod = descriptionList.at(4).mid(4);
         ciph.d->exportable = (descriptionList.size() > 6 && descriptionList.at(6) == QLatin1String("export"));
 
-        ciph.d->bits = cipher->strength_bits;
-        ciph.d->supportedBits = cipher->alg_bits;
+        ciph.d->bits = SSL_CIPHER_get_bits(cipher, &ciph.d->supportedBits);
 
     }
     return ciph;
@@ -267,9 +266,13 @@ init_context:
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
@@ -297,8 +300,10 @@ init_context:
 
     // Enable bug workarounds.
     long options;
-    if (configuration.protocol == QSsl::TlsV1SslV3 || configuration.protocol == QSsl::SecureProtocols)
+    if (configuration.protocol == QSsl::TlsV1SslV3)
         options = SSL_OP_ALL|SSL_OP_NO_SSLv2;
+    else if (configuration.protocol == QSsl::SecureProtocols)
+        options = SSL_OP_ALL|SSL_OP_NO_SSLv2|SSL_OP_NO_SSLv3;
     else
         options = SSL_OP_ALL;
 
@@ -325,7 +330,7 @@ init_context:
         options |= SSL_OP_NO_COMPRESSION;
 #endif
 
-    q_SSL_CTX_set_options(ctx, options);
+    SSL_CTX_set_options(ctx, options);
 
     // Initialize ciphers
     QByteArray cipherString;
@@ -363,7 +368,7 @@ init_context:
         //
         // See also: QSslContext::fromConfiguration()
         if (caCertificate.expiryDate() >= QDateTime::currentDateTime()) {
-            q_X509_STORE_add_cert(ctx->cert_store, (X509 *)caCertificate.handle());
+            q_X509_STORE_add_cert(SSL_CTX_get_cert_store(ctx), (X509 *)caCertificate.handle());
         }
     }
 
@@ -659,13 +664,17 @@ void QSslSocketPrivate::resetDefaultCiphers()
     STACK_OF(SSL_CIPHER) *supportedCiphers = q_SSL_get_ciphers(mySsl);
     for (int i = 0; i < q_sk_SSL_CIPHER_num(supportedCiphers); ++i) {
         if (SSL_CIPHER *cipher = q_sk_SSL_CIPHER_value(supportedCiphers, i)) {
+#if OPENSSL_VERSION_NUMBER < 0x10100005L
             if (cipher->valid) {
+#endif
                 QSslCipher ciph = QSslSocketBackendPrivate::QSslCipher_from_SSL_CIPHER(cipher);
                 if (!ciph.isNull()) {
                     if (!ciph.name().toLower().startsWith(QLatin1String("adh")))
                         ciphers << ciph;
                 }
+#if OPENSSL_VERSION_NUMBER < 0x10100005L
             }
+#endif
         }
     }
 
