--- util/crypt_blowfish.h.orig	2016-05-08 14:30:08 UTC
+++ util/crypt_blowfish.h
@@ -23,7 +23,7 @@
 #endif
 
 extern char *bcrypt(__const char *key, __const char *setting);
-extern char *crypt_r(__const char *key, __const char *setting, void *data);
+extern char *_crypt_r(__const char *key, __const char *setting, void *data);
 
 #ifndef __SKIP_OW
 extern char *crypt_rn(__const char *key, __const char *setting,
