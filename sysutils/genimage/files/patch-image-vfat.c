--- image-vfat.c.orig	2023-01-06 18:01:33 UTC
+++ image-vfat.c
@@ -47,7 +47,7 @@ static int vfat_generate(struct image *image)
 		struct image *child = image_get(part->image);
 		const char *file = imageoutfile(child);
 		const char *target = part->name;
-		char *path = strdupa(target);
+		char *path = strdup(target); // XXX causes memory leak
 		char *next = path;
 
 		while ((next = strchr(next, '/')) != NULL) {
