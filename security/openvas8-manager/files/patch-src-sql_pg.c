--- src/sql_pg.c	2017-08-04 00:41:59.376627000 -0500
+++ src/sql_pg.c	2017-08-04 00:42:16.863937000 -0500
@@ -27,12 +27,12 @@
 #include "tracef.h"
 
 #include <assert.h>
-#include <endian.h>
+#include <sys/endian.h>
 #include <arpa/inet.h>
 #include <glib.h>
 #include <inttypes.h>
 #include <netinet/in.h>
-#include <postgresql/libpq-fe.h>
+#include <libpq-fe.h>
 #include <string.h>
 
 #include <openvas/base/array.h>
