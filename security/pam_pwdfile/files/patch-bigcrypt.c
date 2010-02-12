--- bigcrypt.c.orig	2009-09-04 18:37:28.000000000 -0500
+++ bigcrypt.c	2009-09-04 18:37:30.000000000 -0500
@@ -25,7 +25,7 @@
  */
 
 #include <string.h>
-#include <security/_pam_macros.h>
+#include "_pam_macros.h"
 
 char *crypt(const char *key, const char *salt);
 char *bigcrypt(const char *key, const char *salt);
