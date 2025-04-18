--- ikectl/ikeca.c.orig	2025-04-17 19:27:59 UTC
+++ ikectl/ikeca.c
@@ -47,8 +47,11 @@
 #define SSLDIR		PREFIX "/etc/ssl"
 #endif
 #define SSL_CNF		SSLDIR "/openssl.cnf"
-#define X509_CNF	SSLDIR "/ikex509v3.cnf"
-#define IKECA_CNF	SSLDIR "/ikeca.cnf"
+#ifndef CADIR
+#define CADIR       SSLDIR
+#endif
+#define X509_CNF	CADIR "/ikex509v3.cnf"
+#define IKECA_CNF	CADIR "/ikeca.cnf"
 #define KEYBASE		PREFIX "/etc/iked"
 #ifndef EXPDIR
 #define EXPDIR		PREFIX "/usr/share/iked"
