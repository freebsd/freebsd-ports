--- util/passwordbasedauthentication.c	2025-10-01 02:22:47.000000000 -0700
+++ util/passwordbasedauthentication.c	2025-10-07 22:23:18.428502000 -0700
@@ -14,7 +14,13 @@
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
@@ -208,6 +214,7 @@
   return strlen (setting) > 1 && setting[0] == '$';
 }
 
+#if HAS_CRYPT_R
 /**
  * @brief Create a password hash.
  *
@@ -262,6 +269,7 @@
     free (settings);
   return result;
 }
+#endif /* #if HAS_CRYPT_R */
 
 /**
  * @brief Verify a password hash.
