diff --git src/providers/ldap/sdap_access.c src/providers/ldap/sdap_access.c
index dd04ec512..58a3766fc 100644
--- src/providers/ldap/sdap_access.c
+++ src/providers/ldap/sdap_access.c
@@ -562,9 +562,9 @@ bool nds_check_expired(const char *exp_time_str)
 
     now = time(NULL);
     DEBUG(SSSDBG_TRACE_ALL,
-          "Time info: tzname[0] [%s] tzname[1] [%s] timezone [%ld] "
-           "daylight [%d] now [%ld] expire_time [%ld].\n", tzname[0],
-           tzname[1], timezone, daylight, now, expire_time);
+          "Time info: tzname[0] [%s] tzname[1] [%s] "
+          "now [%ld] expire_time [%ld].\n", tzname[0],
+          tzname[1], now, expire_time);
 
     if (difftime(now, expire_time) > 0.0) {
         DEBUG(SSSDBG_CONF_SETTINGS, "NDS account expired.\n");
@@ -1247,7 +1247,7 @@ static errno_t sdap_access_host(struct ldb_message *user_entry)
     struct ldb_message_element *el;
     unsigned int i;
     char *host;
-    char hostname[HOST_NAME_MAX + 1];
+    char hostname[_POSIX_HOST_NAME_MAX + 1];
 
     el = ldb_msg_find_element(user_entry, SYSDB_AUTHORIZED_HOST);
     if (!el || el->num_values == 0) {
@@ -1255,12 +1255,12 @@ static errno_t sdap_access_host(struct ldb_message *user_entry)
         return ERR_ACCESS_DENIED;
     }
 
-    if (gethostname(hostname, sizeof(hostname)) == -1) {
+    if (gethostname(hostname, _POSIX_HOST_NAME_MAX) == -1) {
         DEBUG(SSSDBG_CRIT_FAILURE,
               "Unable to get system hostname. Access denied\n");
         return ERR_ACCESS_DENIED;
     }
-    hostname[HOST_NAME_MAX] = '\0';
+    hostname[_POSIX_HOST_NAME_MAX] = '\0';
 
     /* FIXME: PADL's pam_ldap also calls gethostbyname() on the hostname
      *        in some attempt to get aliases and/or FQDN for the machine.
