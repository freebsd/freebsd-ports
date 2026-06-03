Can be removed in FreeBSD 15

--- src/providers/ldap/ldap_auth.c.orig	2025-06-24 10:24:24 UTC
+++ src/providers/ldap/ldap_auth.c
@@ -100,6 +100,9 @@ static errno_t check_pwexpire_kerberos(const char *exp
     time_t expire_time;
     int expiration_warning;
     int ret = ERR_INTERNAL;
+#ifndef HAVE_TIMEZONE
+    long daylight = 0;
+#endif
 
     ret = sss_utc_to_time_t(expire_date, "%Y%m%d%H%M%SZ",
                             &expire_time);
