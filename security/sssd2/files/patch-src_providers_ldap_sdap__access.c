Can be removed in FreeBSD 15

--- src/providers/ldap/sdap_access.c.orig	2025-06-24 10:24:24 UTC
+++ src/providers/ldap/sdap_access.c
@@ -551,6 +551,9 @@ bool nds_check_expired(const char *exp_time_str)
     time_t expire_time;
     time_t now;
     errno_t ret;
+#ifndef HAVE_TIMEZONE
+    long daylight = 0;
+#endif
 
     if (exp_time_str == NULL) {
         DEBUG(SSSDBG_TRACE_ALL,
