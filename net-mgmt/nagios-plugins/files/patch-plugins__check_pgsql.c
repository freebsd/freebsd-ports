--- ./plugins/check_pgsql.c.orig	2014-04-16 00:19:03.000000000 +0200
+++ ./plugins/check_pgsql.c	2014-05-20 23:08:11.000000000 +0200
@@ -36,6 +36,7 @@
 #include "utils.h"
 
 #include "netutils.h"
+#include "pg_config_manual.h"
 #include <libpq-fe.h>
 #include <pg_config_manual.h>
 
