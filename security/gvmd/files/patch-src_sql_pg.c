--- src/sql_pg.c	2020-12-31 16:50:03.471244000 -0500
+++ src/sql_pg.c	2020-12-31 16:50:43.332754000 -0500
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
 
