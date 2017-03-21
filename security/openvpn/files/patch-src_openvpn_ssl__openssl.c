From dcfd3b6173d8cdb4658de23db1dd0bd932b390d2 Mon Sep 17 00:00:00 2001
From: Olivier Wahrenberger <olivierw.ml@gmail.com>
Date: Mon, 13 Feb 2017 19:38:26 +0100
Subject: [PATCH] Fix building with LibreSSL 2.5.1 by cleaning a hack.

Similar to what is done in curl: https://github.com/curl/curl/blob/028391df5d84d9fae3433afdee9261d565900355/lib/vtls/openssl.c#L603-L619

Use SSL_CTX_get0_privatekey() for OpenSSL >= 1.0.2

Signed-off-by: Olivier Wahrenberger <olivierw.ml@gmail.com>
Acked-by: Steffan Karger <steffan.karger@fox-it.com>
Message-Id: <20170213183826.73008-1-O2Graphics@users.noreply.github.com>
URL: https://www.mail-archive.com/openvpn-devel@lists.sourceforge.net/msg14045.html
Signed-off-by: Gert Doering <gert@greenie.muc.de>
---
 src/openvpn/ssl_openssl.c | 14 +++++++++++---
 1 file changed, 11 insertions(+), 3 deletions(-)

diff --git a/src/openvpn/ssl_openssl.c b/src/openvpn/ssl_openssl.c
index 8266595..abf69c9 100644
--- ./src/openvpn/ssl_openssl.c~
+++ ./src/openvpn/ssl_openssl.c
@@ -508,10 +508,18 @@ tls_ctx_load_ecdh_params(struct tls_root_ctx *ctx, const char *curve_name
         const EC_GROUP *ecgrp = NULL;
         EVP_PKEY *pkey = NULL;
 
+#if OPENSSL_VERSION_NUMBER >= 0x10002000L && !defined(LIBRESSL_VERSION_NUMBER)
+        pkey = SSL_CTX_get0_privatekey(ctx->ctx);
+#else
         /* Little hack to get private key ref from SSL_CTX, yay OpenSSL... */
-        SSL ssl;
-        ssl.cert = ctx->ctx->cert;
-        pkey = SSL_get_privatekey(&ssl);
+        SSL *ssl = SSL_new(ctx->ctx);
+        if (!ssl)
+        {
+            crypto_msg(M_FATAL, "SSL_new failed");
+        }
+        pkey = SSL_get_privatekey(ssl);
+        SSL_free(ssl);
+#endif
 
         msg(D_TLS_DEBUG, "Extracting ECDH curve from private key");
 
