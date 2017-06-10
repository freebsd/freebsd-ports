From 4e48c77572a9a96a301e362a3646cd3cc7eca0f9 Mon Sep 17 00:00:00 2001
From: Carlos Alberto Lopez Perez <clopez@igalia.com>
Date: Mon, 6 Aug 2012 01:45:51 +0200
Subject: [PATCH] Fix XMPP code detection on s_client starttls xmpp

 * Some XMPP Servers (OpenFire) use double quotes.
 * This makes s_client starttls work with this servers.
 * Tested with OpenFire servers from http://xmpp.net/ ::

     openssl s_client -connect coderollers.com:5222 -starttls xmpp
--- apps/s_client.c.orig	2017-05-25 12:54:38 UTC
+++ apps/s_client.c
@@ -1663,7 +1663,8 @@ int MAIN(int argc, char **argv)
         seen = BIO_read(sbio, mbuf, BUFSIZZ);
         mbuf[seen] = 0;
         while (!strstr
-               (mbuf, "<starttls xmlns='urn:ietf:params:xml:ns:xmpp-tls'")) {
+               (mbuf, "<starttls xmlns='urn:ietf:params:xml:ns:xmpp-tls'") &&
+		!strstr(mbuf, "<starttls xmlns=\"urn:ietf:params:xml:ns:xmpp-tls\"")) {
             if (strstr(mbuf, "/stream:features>"))
                 goto shut;
             seen = BIO_read(sbio, mbuf, BUFSIZZ);
