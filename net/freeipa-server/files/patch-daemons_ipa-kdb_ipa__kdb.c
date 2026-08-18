--- daemons/ipa-kdb/ipa_kdb.c.orig	2025-06-17 07:48:40 UTC
+++ daemons/ipa-kdb/ipa_kdb.c
@@ -87,6 +87,11 @@ static void ipadb_context_free(krb5_context kcontext,
 }
 
 #define LDAPI_URI_PREFIX "ldapi://"
+#ifdef __FreeBSD__
+#define IPA_KDB_LDAPI_DIR "/var/run"
+#else
+#define IPA_KDB_LDAPI_DIR LDAPIDIR
+#endif
 #define LDAPI_PATH_PREFIX "%2fslapd-"
 #define SOCKET_SUFFIX ".socket"
 #define APPEND_PATH_PART(pos, part) \
@@ -104,7 +109,7 @@ static char *ipadb_realm_to_ldapi_uri(char *realm)
     int len;
 
     /* uri length, assume worst case for LDAPIDIR */
-    len = strlen(LDAPI_URI_PREFIX) + strlen(LDAPIDIR) * 3
+    len = strlen(LDAPI_URI_PREFIX) + strlen(IPA_KDB_LDAPI_DIR) * 3
           + strlen(LDAPI_PATH_PREFIX) + strlen(realm)
           + strlen(SOCKET_SUFFIX) + 1;
 
@@ -118,7 +123,7 @@ static char *ipadb_realm_to_ldapi_uri(char *realm)
     APPEND_PATH_PART(p, LDAPI_URI_PREFIX);
 
     /* copy path and escape '/' to '%2f' */
-    for (q = LDAPIDIR; *q; q++) {
+    for (q = IPA_KDB_LDAPI_DIR; *q; q++) {
         if (*q == '/') {
             memcpy(p, "%2f", 3);
             p += 3;
