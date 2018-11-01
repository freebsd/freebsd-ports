--- src/modules/db_mysql/km_dbase.c.orig	2018-10-29 18:08:57 UTC
+++ src/modules/db_mysql/km_dbase.c
@@ -35,7 +35,7 @@
 #include <string.h>
 #include <mysql.h>
 #include <errmsg.h>
-#include <mysql_version.h>
+#include <mysql.h>
 #include "../../core/mem/mem.h"
 #include "../../core/dprint.h"
 #include "../../core/async_task.h"
