--- gmime/gmime-charset.c.orig	Tue Dec 18 15:09:40 2001
+++ gmime/gmime-charset.c	Mon Sep 16 22:48:48 2002
@@ -69,15 +69,23 @@
 		 * codeset  is  a  character  set or encoding identifier like
 		 * ISO-8859-1 or UTF-8.
 		 */
-		char *codeset, *p;
+		char *codeset, *tmp = NULL;
 		
 		codeset = strchr (locale, '.');
 		if (codeset) {
 			codeset++;
 			
-			/* ; is a hack for debian systems and / is a hack for Solaris systems */
-			for (p = codeset; *p && !strchr ("@;/", *p); p++);
-			locale_charset = g_strndup (codeset, (unsigned) (p - codeset));
+			if (strncasecmp(codeset, "iso", 3) == 0 &&
+			    strlen(codeset) > 3 && 
+			    strncasecmp(codeset, "iso-", 4) != 0) {
+			    tmp = (char *)g_malloc(strlen(codeset) + 2);
+			    strcpy(tmp, "iso");
+			    strcat(tmp, "-");
+			    strcat(tmp, (codeset + 3));
+			    codeset = tmp;
+			}
+			locale_charset = g_strndup (codeset, strcspn(codeset, "@;/"));
+			if (tmp != NULL) g_free(tmp);
 			g_strdown (locale_charset);
 		} else {
 			/* charset unknown */
