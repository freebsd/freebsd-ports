#
# ITS#2562: add missing arg to hash_lanman
#
--- libraries/liblutil/passwd.c.orig	Fri May  2 13:29:29 2003
+++ libraries/liblutil/passwd.c	Sun Jun 22 03:08:18 2003
@@ -632,7 +632,7 @@
 {
 	struct berval *hash;
 
-	hash = hash_lanman( scheme, cred );
+	hash = hash_lanman( scheme, cred, text );
 	return memcmp( &hash->bv_val[scheme->bv_len], passwd->bv_val, 32);
 }
 #endif /* SLAPD_LMHASH */
