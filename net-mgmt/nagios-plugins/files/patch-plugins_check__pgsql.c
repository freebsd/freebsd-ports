--- plugins/check_pgsql.c.orig	2015-07-30 21:40:06 UTC
+++ plugins/check_pgsql.c
@@ -36,6 +36,7 @@ const char *email = "devel@nagios-plugin
 #include "utils.h"
 
 #include "netutils.h"
+#include "pg_config_manual.h"
 #include <libpq-fe.h>
 #include <pg_config_manual.h>
 
