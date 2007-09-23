
$FreeBSD$

--- sendd/sendd_local.h.orig
+++ sendd/sendd_local.h
@@ -41,7 +41,7 @@
 #include <openssl/sha.h>
 
 #define	SENDD_NAME	"sendd"
-#define	SNDD_CONF_FILE	"/etc/sendd.conf"
+#define	SNDD_CONF_FILE	"%%PREFIX%%/etc/sendd/sendd.conf"
 
 #define	SND_HASH_SZ	7
 
