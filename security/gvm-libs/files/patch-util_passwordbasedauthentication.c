--- util/passwordbasedauthentication.c	2021-07-08 17:07:24.145438000 -0500
+++ util/passwordbasedauthentication.c	2021-07-08 17:08:24.809605000 -0500
@@ -26,7 +26,11 @@
 // UFC_crypt defines crypt_r when only when __USE_GNU is set
 // this shouldn't affect other implementations
 #define __USE_GNU
+#if defined(__FreeBSD__)
+#include <unistd.h>
+#else
 #include <crypt.h>
+#endif
 // INVALID_HASH is used on verify when the given hash is a NULL pointer.
 // This is done to not directly jump to exit with a INVALID_HASH result
 // but rather keep calculating to make it a little bit harder to guess
