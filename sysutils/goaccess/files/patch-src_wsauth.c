--- src/wsauth.c.orig	2026-03-10 18:36:45 UTC
+++ src/wsauth.c
@@ -107,7 +107,11 @@ create_jwt_payload (const char *sub, long iat, long ex
   const char *aud = "goaccess_ws";
   const char *scope = "report_access";
   char *payload = NULL;
+#if defined(__FreeBSD__)
+  char hostname[_POSIX_HOST_NAME_MAX + 1];
+#else
   char hostname[HOST_NAME_MAX];
+#endif
 
   if (gethostname (hostname, sizeof (hostname)) != 0) {
     perror ("gethostname");
@@ -223,7 +227,11 @@ validate_jwt_claims (const char *payload_json) {
   enum json_type t = JSON_ERROR;
   size_t len = 0, level = 0;
   enum json_type ctx = JSON_ERROR;
+#if defined(__FreeBSD__)
+  char hostname[_POSIX_HOST_NAME_MAX + 1] = { 0 };
+#else
   char hostname[HOST_NAME_MAX] = { 0 };
+#endif
   char *curr_key = NULL;
 
   /* Validation flags/values. */
