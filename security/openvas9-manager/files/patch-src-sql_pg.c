--- src/sql_pg.c	2017-08-06 01:12:18.411221000 -0500
+++ src/sql_pg.c	2017-08-06 01:13:41.241337000 -0500
@@ -26,13 +26,13 @@
 #include "sql.h"
 
 #include <assert.h>
-#include <endian.h>
+#include <sys/endian.h>
 #include <errno.h>
 #include <arpa/inet.h>
 #include <glib.h>
 #include <inttypes.h>
 #include <netinet/in.h>
-#include <postgresql/libpq-fe.h>
+#include <libpq-fe.h>
 #include <stdlib.h>
 #include <string.h>
 
