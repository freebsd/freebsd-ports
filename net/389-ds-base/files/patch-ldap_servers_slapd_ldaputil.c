--- ldap/servers/slapd/ldaputil.c.orig	2026-08-10 21:10:32 UTC
+++ ldap/servers/slapd/ldaputil.c
@@ -849,7 +849,9 @@ ldaputil_get_saslpath()
 {
     char *saslpath = getenv("SASL_PATH");
     if (NULL == saslpath) {
-#if defined(LINUX) && defined(__LP64__)
+#if defined(__FreeBSD__)
+        saslpath = "/usr/local/lib/sasl2";
+#elif defined(LINUX) && defined(__LP64__)
         saslpath = "/usr/lib64/sasl2";
         if (PR_SUCCESS != PR_Access(saslpath, PR_ACCESS_EXISTS)) {
 #ifdef CPU_arm
