--- src/docmd.c.orig	Mon Nov  9 20:08:32 1998
+++ src/docmd.c	Tue Oct 23 14:32:06 2001
@@ -611,7 +624,7 @@
 		c = *cp;
 		if (c & 0200)
 			isbad = TRUE;
-		if (!isalpha(c) && !isdigit(c) && c != '_' && c != '-')
+		if (!isalpha(c) && !isdigit(c) && c != '_' && c != '-' && c != '.' )
 			isbad = TRUE;
 	}
 
