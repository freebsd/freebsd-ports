--- libs/i18n.c.orig	Sun Nov  9 18:05:36 2003
+++ libs/i18n.c	Tue Feb 14 18:50:23 2006
@@ -38,6 +38,19 @@ enum {
  *    All rights reserved.
  */
 
+/* XXX Implement strndup for FreeBSD. */
+static char *
+strndup(const char *str, size_t len) {
+    char *ret;
+
+    if ((str == NULL || len < 0)) return(NULL);
+    ret = (char *)malloc(len + 1);
+    if (ret == NULL) return(NULL);
+    strncpy(ret, str, len);
+    ret[len] = '\0';
+    return(ret);
+}
+
 /* Support function for compute_locale_variants. */
 static int explode_locale(const char *locale, char **language,
 		char **territory, char **codeset, char **modifier)
@@ -118,7 +131,7 @@ static char **compute_locale_variants(co
 		if ((i & ~mask) == 0) {
 			int length = strlen(language) + strlen(territory) 
 				+ strlen(codeset) + strlen(modifier);
-			char *var = (char *) malloc(sizeof(char) * length);
+			char *var = (char *) malloc(sizeof(char) * (length + 1));
 			check_ptr(var, "");
 
 			strcpy(var, language);
@@ -144,7 +157,8 @@ static char **compute_locale_variants(co
 	pos = 0;
 	for (i = 0; i <= mask; i++) {
 		if (progress[i] != NULL) {
-			retval[pos] = progress[i];
+			retval[pos] = strdup(progress[i]);
+			free(progress[i]);
 			++pos;
 		}
 	}
@@ -206,7 +220,7 @@ char **sk_get_language_list()
 		count++;
 	}
 	
-	tab = (char ***)malloc(sizeof(char **) * count);
+	tab = (char ***)malloc(sizeof(char **) * (count + 1));
 	
 	str = strdup(lang);
 	check_ptr(str, "");
@@ -246,7 +260,8 @@ char **sk_get_language_list()
 	while (tab[j] != NULL) {
 		k = 0;
 		while (tab[j][k] != NULL) {
-			retval[pos] = tab[j][k];
+			retval[pos] = strdup(tab[j][k]);
+			free(tab[j][k]);
 			++pos;
 			++k;
 		}
