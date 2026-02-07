--- src/backend.c.orig	2015-12-21 07:40:53 UTC
+++ src/backend.c
@@ -11,7 +11,7 @@
  */
 
 #include "nss-pgsql.h"
-#include <postgresql/libpq-fe.h>
+#include <libpq-fe.h>
 #include <stdlib.h>
 #include <string.h>
 #include <stdio.h>
