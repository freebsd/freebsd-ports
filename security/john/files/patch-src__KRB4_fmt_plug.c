--- src/KRB4_fmt_plug.c.orig	2012-09-17 10:30:39.000000000 +0200
+++ src/KRB4_fmt_plug.c	2015-02-28 20:34:23.845351319 +0100
@@ -182,7 +182,7 @@
 	if (saved_salt->realm[0] != '\0')
 		afs_string_to_key(key, saved_salt->realm, &saved_key.key);
 	else
-		des_string_to_key(key, &saved_key.key);
+		DES_string_to_key(key, &saved_key.key);
 
 	strnzcpy(saved_key.string, key, sizeof(saved_key.string));
 }
