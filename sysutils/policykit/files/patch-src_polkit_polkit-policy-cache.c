--- src/polkit/polkit-policy-cache.c.orig	2007-11-29 01:14:09.000000000 -0500
+++ src/polkit/polkit-policy-cache.c	2007-12-24 14:51:04.000000000 -0500
@@ -98,7 +98,11 @@ PolKitPolicyCache *
 _polkit_policy_cache_new (const char *dirname, polkit_bool_t load_descriptions, PolKitError **error)
 {
         DIR *dir;
+#ifdef HAVE_READDIR64
         struct dirent64 *d;
+#else
+	struct dirent *d;
+#endif
         PolKitPolicyCache *pc;
 
         dir = NULL;
@@ -119,7 +123,11 @@ _polkit_policy_cache_new (const char *di
                 goto out;
         }
 
+#ifdef HAVE_READDIR64
         while ((d = readdir64 (dir)) != NULL) {
+#else
+	while ((d = readdir (dir)) != NULL) {
+#endif
                 char *path;
                 PolKitPolicyFile *pf;
                 PolKitError *pk_error;
