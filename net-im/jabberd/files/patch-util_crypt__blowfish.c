--- util/crypt_blowfish.c.orig	2016-05-08 14:30:08 UTC
+++ util/crypt_blowfish.c
@@ -1106,7 +1106,7 @@ char *crypt_ra(const char *key, const ch
 	return _crypt_blowfish_rn(key, setting, (char *)*data, *size);
 }
 
-char *crypt_r(const char *key, const char *setting, void *data)
+char *_crypt_r(const char *key, const char *setting, void *data)
 {
 	return _crypt_retval_magic(
 		crypt_rn(key, setting, data, CRYPT_OUTPUT_SIZE),
