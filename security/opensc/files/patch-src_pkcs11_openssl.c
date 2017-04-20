--- src/pkcs11/openssl.c.orig	2017-04-20 09:37:43.416459000 +0200
+++ src/pkcs11/openssl.c	2017-04-20 09:38:01.864084000 +0200
@@ -180,7 +180,7 @@
 	e = ENGINE_by_id("gost");
 	if (!e)
 	{
-#if !defined(OPENSSL_NO_STATIC_ENGINE) && !defined(OPENSSL_NO_GOST)
+#if !defined(OPENSSL_NO_STATIC_ENGINE) && !defined(OPENSSL_NO_GOST) && !defined(LIBRESSL_VERSION_NUMBER)
 		ENGINE_load_gost();
 		e = ENGINE_by_id("gost");
 #else
