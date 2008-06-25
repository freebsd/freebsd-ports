diff -ru openssl-0.9.8g.orig/crypto/engine/eng_cryptodev.c crypto/engine/eng_cryptodev.c
--- openssl-0.9.8g.orig/crypto/engine/eng_cryptodev.c	2004-06-15 13:45:42.000000000 +0200
+++ crypto/engine/eng_cryptodev.c	2007-12-16 11:15:12.000000000 +0100
@@ -32,7 +32,7 @@
 #include <openssl/bn.h>
 
 #if (defined(__unix__) || defined(unix)) && !defined(USG) && \
-	(defined(OpenBSD) || defined(__FreeBSD_version))
+	(defined(OpenBSD) || defined(__FreeBSD__))
 #include <sys/param.h>
 # if (OpenBSD >= 200112) || ((__FreeBSD_version >= 470101 && __FreeBSD_version < 500000) || __FreeBSD_version >= 500041)
 #  define HAVE_CRYPTODEV
