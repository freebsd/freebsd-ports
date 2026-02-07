Fix header location.

--- src/pgsql.c.orig	2024-01-08 01:45:50 UTC
+++ src/pgsql.c
@@ -24,7 +24,7 @@
 #ifdef WITH_PGSQL
 
 #include "sql.h"
-#include <postgresql/libpq-fe.h>
+#include <libpq-fe.h>
 
 /* PostgreSQL URL:
 
