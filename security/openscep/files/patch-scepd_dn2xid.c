--- scepd/dn2xid.c.orig	Mon Mar 26 14:36:47 2001
+++ scepd/dn2xid.c	Thu May 19 16:26:46 2005
@@ -11,6 +11,7 @@
 #include <ldap.h>
 #include <unistd.h>
 #include <openssl/bio.h>
+#include <openssl/evp.h>
 #include <openssl/x509.h>
 #include <openssl/err.h>
 #include <fingerprint.h>
