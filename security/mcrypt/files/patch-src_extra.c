--- src/extra.c.orig	Mon Oct  2 09:38:07 2000
+++ src/extra.c	Thu Mar 22 20:14:15 2001
@@ -289,7 +289,7 @@
 	int i;
 
 	for (i = 0; i < size; i++) {
-		str[i] = _tolower(str[i]);
+		str[i] = tolower(str[i]);
 	}
 }
 
