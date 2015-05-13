From 622409947f6e64fcabbf2b4da2ed086abc06ed85 Mon Sep 17 00:00:00 2001
From: Bernard Spil <Sp1l@users.noreply.github.com>
Date: Wed, 15 Apr 2015 11:09:32 +0200
Subject: [PATCH] LibreSSL added ALPN support in 2.1.3
Link: https://github.com/pyca/cryptography/pull/1849

--- src/cryptography/hazmat/bindings/openssl/ssl.py.orig	2015-04-24 12:57:06 UTC
+++ src/cryptography/hazmat/bindings/openssl/ssl.py
@@ -526,7 +526,7 @@ static const long Cryptography_HAS_NEXTP
 #endif
 
 /* ALPN was added in OpenSSL 1.0.2. */
-#if OPENSSL_VERSION_NUMBER < 0x10002001L
+#if OPENSSL_VERSION_NUMBER < 0x10002001L  && !defined(LIBRESSL_VERSION_NUMBER)
 int (*SSL_CTX_set_alpn_protos)(SSL_CTX *,
                                const unsigned char *,
                                unsigned) = NULL;
