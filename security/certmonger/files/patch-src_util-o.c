This can be removed once FreeBSD 13 stops being supported

--- src/util-o.c.orig	2024-06-10 21:15:16 UTC
+++ src/util-o.c
@@ -19,6 +19,7 @@
 
 #include <sys/types.h>
 #include <sys/stat.h>
+#include <sys/param.h>
 #include <errno.h>
 #include <fcntl.h>
 #include <grp.h>
@@ -551,7 +552,11 @@ util_EVP_PKEY_dup(EVP_PKEY *pkey,
 
 static EVP_PKEY *
 util_EVP_PKEY_dup(EVP_PKEY *pkey,
+#if __FreeBSD_version >= 1400092
 		  int (*i2d)(const EVP_PKEY *, unsigned char **),
+#else
+		  int (*i2d)(EVP_PKEY *, unsigned char **),
+#endif
 		  EVP_PKEY *(*d2i)(int, EVP_PKEY **, const unsigned char **, long))
 {
 	EVP_PKEY *k;
