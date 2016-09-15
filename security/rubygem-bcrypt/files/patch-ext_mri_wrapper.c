--- ext/mri/wrapper.c.orig	2016-09-01 08:48:10 UTC
+++ ext/mri/wrapper.c
@@ -185,13 +185,6 @@ char *crypt_ra(__CONST char *key, __CONS
 	return _crypt_blowfish_rn(key, setting, (char *)*data, *size);
 }
 
-char *crypt_r(__CONST char *key, __CONST char *setting, void *data)
-{
-	return _crypt_retval_magic(
-		crypt_rn(key, setting, data, CRYPT_OUTPUT_SIZE),
-		setting, (char *)data);
-}
-
 #define __crypt_gensalt_rn crypt_gensalt_rn
 #define __crypt_gensalt_ra crypt_gensalt_ra
 #define __crypt_gensalt crypt_gensalt
