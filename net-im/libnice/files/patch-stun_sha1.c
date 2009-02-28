--- stun/sha1.c.orig	2009-02-27 23:05:24.000000000 -0500
+++ stun/sha1.c	2009-02-27 23:05:33.000000000 -0500
@@ -13,6 +13,7 @@
  */
 
 #include "sha1.h"
+#include <sys/endian.h>
 #include <string.h>
 
 
