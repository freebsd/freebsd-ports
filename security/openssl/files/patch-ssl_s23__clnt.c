From 98fe34c30fe1fb7be3023e4c1458da73f8e55da9 Mon Sep 17 00:00:00 2001
From: Kurt Roeckx <kurt@roeckx.be>
Date: Thu, 2 Nov 2017 18:53:16 +0100
Subject: [PATCH] Fix no-ssl3-method build

Reviewed-by: Rich Salz <rsalz@openssl.org>
GH: #4649
---
 ssl/s23_clnt.c | 2 ++
 1 file changed, 2 insertions(+)

diff --git a/ssl/s23_clnt.c b/ssl/s23_clnt.c
index 92f41dd549a..05b892b7238 100644
--- ssl/s23_clnt.c.orig
+++ ssl/s23_clnt.c
@@ -757,10 +757,12 @@ static int ssl23_get_server_hello(SSL *s)
                 s->version = TLS1_VERSION;
                 s->method = TLSv1_client_method();
                 break;
+#ifndef OPENSSL_NO_SSL3_METHOD
             case SSL3_VERSION:
                 s->version = SSL3_VERSION;
                 s->method = SSLv3_client_method();
                 break;
+#endif
             }
             SSLerr(SSL_F_SSL23_GET_SERVER_HELLO, SSL_R_UNSUPPORTED_PROTOCOL);
             ssl3_send_alert(s, SSL3_AL_FATAL, SSL_AD_PROTOCOL_VERSION);
