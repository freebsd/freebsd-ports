--- src/providers/ldap/sdap_access.c.orig	2023-05-05 08:11:07 UTC
+++ src/providers/ldap/sdap_access.c
@@ -24,6 +24,7 @@
 
 #include "config.h"
 
+#include <sys/param.h>
 #include <time.h>
 #include <security/pam_modules.h>
 #include <talloc.h>
@@ -568,9 +569,9 @@ bool nds_check_expired(const char *exp_time_str)
 
     now = time(NULL);
     DEBUG(SSSDBG_TRACE_ALL,
-          "Time info: tzname[0] [%s] tzname[1] [%s] timezone [%ld] "
-          "daylight [%d] now [%"SPRItime"] expire_time [%"SPRItime"].\n",
-          tzname[0], tzname[1], timezone, daylight, now, expire_time);
+          "Time info: tzname[0] [%s] tzname[1] [%s] "
+          "now [%"SPRItime"] expire_time [%"SPRItime"].\n",
+          tzname[0], tzname[1], now, expire_time);
 
     if (difftime(now, expire_time) > 0.0) {
         DEBUG(SSSDBG_CONF_SETTINGS, "NDS account expired.\n");
@@ -1286,7 +1287,7 @@ static errno_t sdap_access_host(struct ldb_message *us
 {
     errno_t ret;
     struct ldb_message_element *el;
-    char hostname[HOST_NAME_MAX + 1];
+    char hostname[MAXHOSTNAMELEN + 1];
     struct addrinfo *res = NULL;
     struct addrinfo hints;
 
@@ -1301,7 +1302,7 @@ static errno_t sdap_access_host(struct ldb_message *us
               "Unable to get system hostname. Access denied\n");
         return ERR_ACCESS_DENIED;
     }
-    hostname[HOST_NAME_MAX] = '\0';
+    hostname[MAXHOSTNAMELEN] = '\0';
 
     /* Canonicalize the hostname */
     memset(&hints, 0, sizeof(struct addrinfo));
