--- md5auth/hmac_md5.c.orig	2009-11-23 11:45:41.000000000 +0200
+++ md5auth/hmac_md5.c	2011-02-21 02:27:21.000000000 +0200
@@ -1,7 +1,7 @@
 #include <string.h>
 #include <sys/types.h>
 #include "global.h"
-#include "md5.h"
+#include <md5.h>
 
 /*
 ** Function: hmac_md5 (RFC 2104)
