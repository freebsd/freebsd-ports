--- auth_postgres.c.orig	Thu Mar 18 13:04:49 2004
+++ auth_postgres.c	Thu Mar 18 13:04:55 2004
@@ -7,7 +7,7 @@
 #include <stdlib.h>
 #include <string.h>
 
-#include <postgresql/libpq-fe.h>
+#include <libpq-fe.h>
 
 #include "nntpd.h"
 #include "aconfig.h"
