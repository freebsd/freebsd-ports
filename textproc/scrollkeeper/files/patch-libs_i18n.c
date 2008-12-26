--- libs/i18n.c.orig	Sun Nov  9 18:05:36 2003
+++ libs/i18n.c	Tue Feb 14 18:50:23 2006
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
