--- ext/mri/ow-crypt.h.orig	2016-09-01 08:48:28 UTC
+++ ext/mri/ow-crypt.h
@@ -16,7 +16,6 @@
 
 #ifndef __SKIP_GNU
 extern char *crypt(__CONST char *key, __CONST char *setting);
-extern char *crypt_r(__CONST char *key, __CONST char *setting, void *data);
 #endif
 
 #ifndef __SKIP_OW
