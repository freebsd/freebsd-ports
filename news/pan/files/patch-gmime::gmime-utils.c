
$FreeBSD$

--- gmime/gmime-utils.c	2001/08/22 18:22:18	1.1
+++ gmime/gmime-utils.c	2001/08/22 18:35:26
@@ -32,7 +32,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <ctype.h>
-#include <langinfo.h>
+#include <locale.h>
 
 #define d(x)
 
@@ -128,11 +128,12 @@
 get_codeset (void)
 {
 	const gchar * codeset;
+	gchar *s;
 
-	codeset = nl_langinfo (CODESET);
-	if (!codeset || !*codeset)
-		codeset = DEFAULT_CODESET;
-
+        codeset = DEFAULT_CODESET;
+        if ((s = setlocale(LC_CTYPE, NULL)) != NULL)
+		if ((s = strchr(s, '.')) != NULL)
+                        codeset = s + 1;
 	return codeset;
 }
 
