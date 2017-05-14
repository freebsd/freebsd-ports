From 69793ae0c1b3b6cb2e4baecc224ea714707ac329 Mon Sep 17 00:00:00 2001
From: Piotr Kubaj <pkubaj@anongoth.pl>
Date: Fri, 12 May 2017 14:24:37 +0100
Subject: [PATCH 1/1] Fix build with LibreSSL 2.5.1 and higher.

We don't actually care if we use the read or write state; we're only
calculating the cipher/protocol overheads which are the same in both
directions.

In LibreSSL they were all removed in
https://github.com/libressl-portable/openbsd/commit/122ecd906da7
and the read side was restored in
https://github.com/libressl-portable/openbsd/commit/0d7a7d5f5a44
so just use that.

Signed-off-by: Piotr Kubaj <pkubaj@anongoth.pl>
Signed-off-by: David Woodhouse <dwmw2@infradead.org>
--- openssl-dtls.c.orig	2016-12-06 13:03:51 UTC
+++ openssl-dtls.c
@@ -100,8 +100,8 @@ static int dtls_get_data_mtu(struct open
 	}
 #else
 	/* OpenSSL <= 1.0.2 only supports CBC ciphers with PSK */
-	ivlen = EVP_CIPHER_iv_length(EVP_CIPHER_CTX_cipher(vpninfo->dtls_ssl->enc_write_ctx));
-	maclen = EVP_MD_CTX_size(vpninfo->dtls_ssl->write_hash);
+	ivlen = EVP_CIPHER_iv_length(EVP_CIPHER_CTX_cipher(vpninfo->dtls_ssl->enc_read_ctx));
+	maclen = EVP_MD_CTX_size(vpninfo->dtls_ssl->read_hash);
 	blocksize = ivlen;
 	pad = 1;
 #endif
