--- cherokee/request.h.orig	Tue Jun 28 01:25:32 2005
+++ cherokee/request.h	Sat Sep 17 21:22:39 2005
@@ -25,6 +25,8 @@
 #ifndef CHEROKEE_REQUEST_H
 #define CHEROKEE_REQUEST_H
 
+#include <sys/types.h>
+
 #include "common.h"
 #include "url.h"
 #include "http.h"
