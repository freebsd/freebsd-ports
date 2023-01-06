--- image-rauc.c.orig	2023-01-06 17:59:29 UTC
+++ image-rauc.c
@@ -95,7 +95,7 @@ static int rauc_generate(struct image *image)
 		}
 
 		/* create parent directories if target needs it */
-		path = strdupa(target);
+		path = strdup(target); // XXX causes memory leak
 		tmp = strrchr(path, '/');
 		if (tmp) {
 			*tmp = '\0';
