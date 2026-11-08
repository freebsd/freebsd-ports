--- util/ipa_ldap.h.orig	2026-09-05 20:54:40 UTC
+++ util/ipa_ldap.h
@@ -20,7 +20,7 @@
 
 #include <ldap.h>
 
-#define DEFAULT_CA_CERT_FILE "/etc/ipa/ca.crt"
+#define DEFAULT_CA_CERT_FILE "%%PREFIX%%/etc/ipa/ca.crt"
 
 #define LDAP_SASL_EXTERNAL "EXTERNAL"
 #define LDAP_SASL_GSSAPI "GSSAPI"
