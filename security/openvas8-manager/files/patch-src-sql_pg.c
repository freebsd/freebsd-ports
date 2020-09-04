--- src/sql_pg.c.orig	2015-12-08 07:09:33 UTC
+++ src/sql_pg.c
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
