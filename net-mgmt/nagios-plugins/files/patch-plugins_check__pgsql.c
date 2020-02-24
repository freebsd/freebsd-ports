--- plugins/check_pgsql.c.orig	2019-12-04 21:53:08 UTC
+++ plugins/check_pgsql.c
@@ -36,6 +36,7 @@ const char *email = "devel@nagios-plugins.org";
 #include "utils.h"
 
 #include "netutils.h"
+#include "pg_config_manual.h"
 #include <libpq-fe.h>
 #include <pg_config_manual.h>
 
@@ -162,7 +163,7 @@ main (int argc, char **argv)
 	pgoptions = NULL;  /* special options to start up the backend server */
 	pgtty = NULL;      /* debugging tty for the backend server */
 
-	setlocale (LC_ALL, "");
+	setlocale (LC_ALL, ""); setlocale(LC_NUMERIC, "C");
 	bindtextdomain (PACKAGE, LOCALEDIR);
 	textdomain (PACKAGE);
 
