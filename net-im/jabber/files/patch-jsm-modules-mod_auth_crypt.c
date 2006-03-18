--- jsm/modules/mod_auth_crypt.c.orig	Thu May  6 00:00:20 2004
+++ jsm/modules/mod_auth_crypt.c	Thu May  6 00:00:01 2004
@@ -28,7 +28,7 @@
  * 
  * --------------------------------------------------------------------------*/
 #include "jsm.h"
-#include "crypt.h"
+#include <unistd.h>
 
 #define HASH_CRYPT 1
 #define HASH_SHA1  2
