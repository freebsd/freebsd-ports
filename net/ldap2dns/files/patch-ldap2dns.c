--- ldap2dns.c.orig	Thu Oct 19 20:54:23 2006
+++ ldap2dns.c	Sun Oct 29 16:41:24 2006
@@ -18,7 +18,7 @@
 #include <sys/types.h>
 
 #define UPDATE_INTERVAL 59
-#define LDAP_CONF "/etc/ldap.conf"
+#define LDAP_CONF "%%PREFIX%%/etc/openldap/ldap.conf"
 #define OUTPUT_DATA 1
 #define OUTPUT_DB 2
 #define MAXHOSTS 10
