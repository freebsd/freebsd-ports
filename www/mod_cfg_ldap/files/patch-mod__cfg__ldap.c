--- mod_cfg_ldap.c.orig	2004-09-16 17:02:15 UTC
+++ mod_cfg_ldap.c
@@ -45,6 +45,7 @@
 #include "http_log.h"
 #include "http_request.h"
 #include "apr_strings.h"
+#define LDAP_DEPRECATED 1
 #include "ldap.h"
 
 #define CFG_LDAP_NO_SUCH_VHOST "cfg_ldap_no_such_vhost"
