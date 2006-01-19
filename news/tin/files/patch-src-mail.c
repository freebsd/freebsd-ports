--- src/mail.c.orig	Wed Jan 18 23:29:18 2006
+++ src/mail.c	Wed Jan 18 23:29:28 2006
@@ -369,7 +369,7 @@
 			space = strlen(ptr) + 1;
 			groupname = my_malloc(space);
 		} else {
-			while (strlen(ptr) > space) { /* realloc needed? */
+			while (strlen(ptr) + 1 > space) { /* realloc needed? */
 				space <<= 1; /* double size */
 				groupname = my_realloc(groupname, space);
 			}
