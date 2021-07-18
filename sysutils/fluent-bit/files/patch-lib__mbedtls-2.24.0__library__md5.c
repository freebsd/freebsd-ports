--- lib/mbedtls-2.24.0/library/md5.c.orig	2021-06-23 09:56:17.365471000 +0200
+++ lib/mbedtls-2.24.0/library/md5.c	2021-06-23 09:56:30.205899000 +0200
@@ -422,8 +422,7 @@
     { "message digest" },
     { "abcdefghijklmnopqrstuvwxyz" },
     { "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789" },
-    { "12345678901234567890123456789012345678901234567890123456789012"
-      "345678901234567890" }
+    { "12345678901234567890123456789012345678901234567890123456789012345678901234567890" }
 };
 
 static const size_t md5_test_buflen[7] =
