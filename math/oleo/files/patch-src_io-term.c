--- src/io-term.c.orig	2008-02-08 16:43:28.000000000 +0100
+++ src/io-term.c	2008-02-08 16:45:06.000000000 +0100
@@ -220,6 +220,7 @@
 {
   int	set_opt = 1;
   int	i, l;
+  int *tmp;
   char	*p;
 
   while (*ptr == ' ')
@@ -234,9 +235,11 @@
 
 		if (Preferences[i].copynext) {
 			ptr += strlen(Preferences[i].name) + 1;
-			((char *)Preferences[i].var) = strdup(ptr);
-		} else if (Preferences[i].var)
-			*((int *)Preferences[i].var) = Preferences[i].value;
+			Preferences[i].var = strdup(ptr);
+		} else if (Preferences[i].var) {
+         tmp = Preferences[i].var;
+			*tmp = Preferences[i].value;
+      }
 
 		if (Preferences[i].cont == 0)
 			return 1;
