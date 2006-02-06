--- src/lib/dict.c.orig	Mon Feb  6 10:15:41 2006
+++ src/lib/dict.c	Mon Feb  6 10:16:07 2006
@@ -1207,7 +1207,7 @@
 	if (!name) return NULL;
 
 	hash = dict_hashname(name);
-	hash = lrad_hash_update(&attr, sizeof(&attr), hash);
+	hash = lrad_hash_update(&attr, sizeof(attr), hash);
 
 	return lrad_hash_table_finddata(values_byname, hash);
 }
