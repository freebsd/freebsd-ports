--- plugins/check_pgsql.c.orig	2008-01-30 11:17:46.000000000 +0100
+++ plugins/check_pgsql.c	2008-01-30 11:18:00.000000000 +0100
@@ -43,6 +43,7 @@
 #include "utils.h"
 
 #include "netutils.h"
+#include "pg_config_manual.h"
 #include <libpq-fe.h>
 
 #define DEFAULT_DB "template1"
