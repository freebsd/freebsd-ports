--- src/fontfile/catalogue.c.orig
+++ src/fontfile/catalogue.c
@@ -156,7 +156,7 @@ CatalogueRescan (FontPathElementPtr fpe)
     while (entry = readdir(dir), entry != NULL)
     {
 	snprintf(link, sizeof link, "%s/%s", path, entry->d_name);
-	len = readlink(link, dest, sizeof dest);
+	len = readlink(link, dest, sizeof dest - 1);
 	if (len < 0)
 	    continue;
 
