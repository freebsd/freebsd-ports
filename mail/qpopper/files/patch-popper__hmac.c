--- popper/hmac.c.orig	2008-06-27 17:40:15.000000000 -0700
+++ popper/hmac.c	2011-06-08 21:57:42.000000000 -0700
@@ -13,7 +13,11 @@
 #include <stdio.h>
 #include <string.h>
 #include <sys/types.h>
-#include "md5.h"
+#include <sys/types.h>
+#include <md5.h>
+
+#define UINT4 u_int32_t
+
 #include "hmac-md5.h"
 

