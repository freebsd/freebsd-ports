--- popper/hmac.c.orig	2008-06-28 08:40:15.000000000 +0800
+++ popper/hmac.c	2021-03-10 13:06:10.554159000 +0700
@@ -13,7 +13,10 @@
 #include <stdio.h>
 #include <string.h>
 #include <sys/types.h>
-#include "md5.h"
+#include <md5.h>
+
+#define UINT4 u_int32_t
+
 #include "hmac-md5.h"
 
 
