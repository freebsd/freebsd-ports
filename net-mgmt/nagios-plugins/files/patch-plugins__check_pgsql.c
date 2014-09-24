--- plugins/check_pgsql.c.orig	2014-04-15 22:19:03 UTC
+++ plugins/check_pgsql.c
@@ -36,6 +36,7 @@
 #include "utils.h"
 
 #include "netutils.h"
+#include "pg_config_manual.h"
 #include <libpq-fe.h>
 #include <pg_config_manual.h>
 
