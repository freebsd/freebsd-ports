--- lib_calc.c.orig	Mon Feb  7 22:08:08 2000
+++ lib_calc.c	Mon Feb  7 22:10:42 2000
@@ -407,9 +407,13 @@
 		if (ent == NULL) {
 			/* just assume . is home if all else fails */
 			home = ".";
+		} else {
+			home = (char *)malloc(strlen(ent->pw_dir)+1);
+			if (home == NULL)
+				home = ".";
+			else
+				strcpy(home, ent->pw_dir);
 		}
-		home = (char *)malloc(strlen(ent->pw_dir)+1);
-		strcpy(home, ent->pw_dir);
 	}
 
 	/* determine the $PAGER value */
