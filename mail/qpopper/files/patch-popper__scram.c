--- popper/scram.c.orig	2008-06-21 18:32:58.000000000 -0700
+++ popper/scram.c	2011-06-08 21:50:54.000000000 -0700
@@ -18,7 +18,10 @@
 #include <netinet/in.h>
 
 #include "uint4.h"
-#include "md5.h"
+#include <md5.h>
+
+#define UINT4 u_int32_t
+
 #include "hmac-md5.h"
 #include "scram.h"

