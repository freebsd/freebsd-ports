--- readnews/header.c.orig	1994-08-25 22:15:09.000000000 +0200
+++ readnews/header.c	2014-02-07 16:54:07.000000000 +0100
@@ -142,7 +142,7 @@
 	memset((char *) hp, 0, sizeof(header));
 	while (hfgets(buf, sizeof(buf), f)) {
 		if (buf[0] == '\n')
-			return;
+			return 0;
 		if (isupper(buf[0]) && (colon = strchr(buf, ':')) &&
 		    (space = strchr(buf, ' ')) && (colon + 1 == space)) {
 			*colon = '\0';
@@ -220,6 +220,7 @@
 			}
 		}
 	}
+	return 0;
 }
 
 
