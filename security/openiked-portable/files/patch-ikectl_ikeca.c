--- ikectl/ikeca.c.orig	2025-04-09 19:47:21 UTC
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
@@ -1118,7 +1121,7 @@ ca_setup(char *caname, int create, int quiet, char *pa
 		err(1, "calloc");
 
 	ca->caname = strdup(caname);
-	len = snprintf(ca->sslpath, sizeof(ca->sslpath), SSLDIR "/%s", caname);
+	len = snprintf(ca->sslpath, sizeof(ca->sslpath), CADIR "/%s", caname);
 	if (len < 0 || (size_t)len >= sizeof(ca->sslpath))
 		err(1, "%s: snprintf", __func__);
 
