Index: src/ssl.c
===================================================================
--- src/ssl.c	(revision 76)
+++ src/ssl.c	(working copy)
@@ -1754,12 +1754,13 @@
     if (SSL_OptionSet(s, SSL_HANDSHAKE_AS_SERVER, server) != SECSuccess)
         goto error;
 
-    if (SSL_OptionSet(s, SSL_ENABLE_SSL2, ssl2) != SECSuccess)
-        goto error;
+    /* Don't fail if enabling SSL2 options doesn't succeed as it may
+     * be disabled in NSS. So just ignore the return value from
+     * SSL_OptionSet().
+     */
+    SSL_OptionSet(s, SSL_ENABLE_SSL2, ssl2);
+    SSL_OptionSet(s, SSL_V2_COMPATIBLE_HELLO, ssl2);
 
-    if (SSL_OptionSet(s, SSL_V2_COMPATIBLE_HELLO, ssl2) != SECSuccess)
-        goto error;
-
     if (SSL_OptionSet(s, SSL_ENABLE_SSL3, ssl3)  != SECSuccess)
         goto error;
 
