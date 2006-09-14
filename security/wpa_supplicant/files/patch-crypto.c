
$FreeBSD$

--- crypto.c.orig
+++ crypto.c
@@ -12,6 +12,7 @@
  * See README and COPYING for more details.
  */
 
+#include <sys/types.h>
 #include <openssl/md4.h>
 #include <openssl/des.h>
 
