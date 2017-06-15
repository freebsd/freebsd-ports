From cc92c25a5fcbc1d3e4ebb8771fe87d961f2079bf Mon Sep 17 00:00:00 2001
From: Vanilla Hsu <vanilla@fatpipi.com>
Date: Sat, 14 Jan 2017 09:36:57 +0800
Subject: [PATCH] Fix building with libressl.

---
 src/hitch.c | 2 +-
 1 file changed, 1 insertion(+), 1 deletion(-)

diff --git a/src/hitch.c b/src/hitch.c
index 5b48680..03b4580 100644
--- src/hitch.c.orig	2016-12-22 13:48:49 UTC
+++ src/hitch.c
@@ -683,7 +683,7 @@ load_privatekey(SSL_CTX *ctx, const char
 		return NULL;
 	}
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 #define SSL_CTX_get_default_passwd_cb(ctx) (ctx->default_passwd_callback)
 #define SSL_CTX_get_default_passwd_cb_userdata(ctx) (ctx->default_passwd_callback_userdata)
 #endif
