--- ./src/util/crypto/nss/nss_sha512crypt.c.orig	2011-08-29 11:39:05.000000000 -0400
+++ ./src/util/crypto/nss/nss_sha512crypt.c	2011-10-13 12:15:03.000000000 -0400
@@ -10,7 +10,7 @@
 
 #include "config.h"
 
-#include <endian.h>
+#include <sys/endian.h>
 #include <errno.h>
 #include <limits.h>
 #include <stdbool.h>
@@ -267,7 +267,7 @@
         goto done;
     }
 
-    cp = __stpncpy(buffer, sha512_salt_prefix, SALT_PREF_SIZE);
+    cp = stpncpy(buffer, sha512_salt_prefix, SALT_PREF_SIZE);
     buflen -= SALT_PREF_SIZE;
 
     if (rounds_custom) {
@@ -285,7 +285,7 @@
         ret = ERANGE;
         goto done;
     }
-    cp = __stpncpy(cp, salt, salt_len);
+    cp = stpncpy(cp, salt, salt_len);
     *cp++ = '$';
     buflen -= salt_len + 1;
 
