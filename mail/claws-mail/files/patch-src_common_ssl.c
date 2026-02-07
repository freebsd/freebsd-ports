--- src/common/ssl.c.orig	2018-12-21 09:33:36 UTC
+++ src/common/ssl.c
@@ -196,6 +196,9 @@ const gchar *claws_ssl_get_cert_file(void)
 #ifndef G_OS_WIN32
 	const char *cert_files[]={
 		"/etc/ssl/cert.pem",
+		// Also search in LOCALBASE directory to
+		// workaround potential lack of /etc symlink
+		"%%LOCALBASE%%/share/certs/ca-root-nss.crt",
 		"/etc/pki/tls/certs/ca-bundle.crt",
 		"/etc/certs/ca-bundle.crt",
 		"/etc/ssl/ca-bundle.pem",
