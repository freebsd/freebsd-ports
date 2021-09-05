--- util/passwordbasedauthentication.c	2021-08-03 06:50:41.000000000 -0500
+++ util/passwordbasedauthentication.c	2021-09-04 20:54:26.630524000 -0500
@@ -26,7 +26,13 @@
 // UFC_crypt defines crypt_r when only when __USE_GNU is set
 // this shouldn't affect other implementations
 #define __USE_GNU
+#if defined(__FreeBSD__)
+#if HAS_CRYPT_R
+#include <unistd.h>
+#endif
+#else
 #include <crypt.h>
+#endif
 // INVALID_HASH is used on verify when the given hash is a NULL pointer.
 // This is done to not directly jump to exit with a INVALID_HASH result
 // but rather keep calculating to make it a little bit harder to guess
@@ -173,6 +179,7 @@
   return strlen (setting) > 1 && setting[0] == '$';
 }
 
+#if HAS_CRYPT_R
 char *
 pba_hash (struct PBASettings *setting, const char *password)
 {
@@ -276,3 +283,4 @@
     free (tmp);
   return result;
 }
+#endif /* #if HAS_CRYPT_R */
