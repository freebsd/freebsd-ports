--- ldap2dns.c.orig	Fri Dec 16 20:49:47 2005
+++ ldap2dns.c	Thu Jan 12 18:36:43 2006
@@ -15,7 +15,7 @@
 #include <unistd.h>
 
 #define UPDATE_INTERVALL 59
-#define LDAP_CONF "/etc/ldap/ldap.conf"
+#define LDAP_CONF "%%PREFIX%%/etc/openldap/ldap.conf"
 #define OUTPUT_DATA 1
 #define OUTPUT_DB 2
 #define MAXHOSTS 10
