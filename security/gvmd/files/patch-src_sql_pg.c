--- src/sql_pg.c	2026-03-09 06:35:01.000000000 -0700
+++ src/sql_pg.c	2026-03-16 18:52:29.149579000 -0700
@@ -15,13 +15,13 @@
 
 #include <arpa/inet.h>
 #include <assert.h>
-#include <endian.h>
+#include <sys/endian.h>
 #include <errno.h>
 #include <glib.h>
 #include <gvm/base/array.h>
 #include <inttypes.h>
 #include <netinet/in.h>
-#include <postgresql/libpq-fe.h>
+#include <libpq-fe.h>
 #include <stdlib.h>
 #include <string.h>
 
