--- libs/i18n.c.orig	Wed Apr 23 00:48:20 2003
+++ libs/i18n.c	Wed Apr 23 00:59:24 2003
@@ -38,6 +38,19 @@
  *    All rights reserved.
  */
 
+/* XXX Implement strndup for FreeBSD. */
+static char *
+strndup(const char *str, int len) {
+    char *ret;
+
+    if ((str == NULL || len < 0)) return(NULL);
+    ret = (char *)malloc(len + 1);
+    if (ret == NULL) return(NULL);
+    memcpy(ret, str, len);
+    ret[len] = '\0';
+    return(ret);
+}
+
 /* Support function for compute_locale_variants. */
 static int explode_locale(const char *locale, char **language,
 		char **territory, char **codeset, char **modifier)
