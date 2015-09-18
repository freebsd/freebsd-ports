$OpenBSD: patch-src_ssl_Ssl_c,v 1.3 2015/07/24 12:50:38 jasper Exp $

From f494be42d356fac9d53cb60f27464418a1a2f0f9 Mon Sep 17 00:00:00 2001
From: Jasper Lievisse Adriaanse <jasper@humppa.nl>
Date: Fri, 24 Jul 2015 09:14:52 +0200
Subject: [PATCH] Guard SSLv3_client_method() in case no SSLv3 support is present

--- src/ssl/Ssl.c.orig	2015-06-02 10:09:34 UTC
+++ src/ssl/Ssl.c
@@ -267,11 +267,16 @@ T Ssl_new(char *clientpemfile, Ssl_Versi
 #endif
                         break;
                 case SSL_V3:
+#ifdef OPENSSL_NO_SSL3
+                        LogError("SSL: SSLv3 not supported\n");
+                        goto sslerror;
+#else
                         if (Run.flags & Run_FipsEnabled) {
                                 LogError("SSL: SSLv3 is not allowed in FIPS mode -- use TLS\n");
                                 goto sslerror;
                         }
                         method = SSLv3_client_method();
+#endif
                         break;
                 case SSL_TLSV1:
                         method = TLSv1_client_method();
