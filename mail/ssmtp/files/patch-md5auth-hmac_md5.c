--- md5auth/hmac_md5.c.orig	2009-11-23 09:45:41 UTC
+++ md5auth/hmac_md5.c
@@ -1,7 +1,7 @@
 #include <string.h>
 #include <sys/types.h>
 #include "global.h"
-#include "md5.h"
+#include <md5.h>
 
 /*
 ** Function: hmac_md5 (RFC 2104)
