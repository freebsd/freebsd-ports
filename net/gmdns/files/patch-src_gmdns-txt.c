--- src/gmdns-txt.c.orig	Sun Jun  6 01:27:19 2004
+++ src/gmdns-txt.c	Sun Jun  6 01:29:38 2004
@@ -106,6 +106,7 @@
 			return hash;
 		}
 
+		name = g_strndup (work, namelen);
 		value = g_strndup (work + namelen + 1, valuelen);
 
 		if (hash == NULL) {
