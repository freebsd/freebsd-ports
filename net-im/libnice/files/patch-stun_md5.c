--- stun/md5.c.orig	2009-02-27 23:04:31.000000000 -0500
+++ stun/md5.c	2009-02-27 23:05:15.000000000 -0500
@@ -13,6 +13,7 @@
  */
 
 #include "md5.h"
+#include <sys/endian.h>
 #include <string.h>
 
 /* ===== start - public domain MD5 implementation ===== */
