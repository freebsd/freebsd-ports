--- md5auth/hmac_md5.c.orig	2009-11-01 23:54:54.000000000 +0200
+++ md5auth/hmac_md5.c	2009-11-01 23:55:07.000000000 +0200
@@ -1,7 +1,7 @@
 #include "global.h"
-#include "md5.h"
 #include <string.h>
 #include <sys/types.h>
+#include <md5.h>
 
 /*
 ** Function: hmac_md5 (RFC 2104)

