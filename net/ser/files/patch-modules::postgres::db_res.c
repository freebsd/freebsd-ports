
$FreeBSD$

--- modules/postgres/db_res.c.orig	Tue Apr  8 04:25:35 2003
+++ modules/postgres/db_res.c	Tue Apr 13 22:27:28 2004
@@ -38,6 +38,7 @@
 
 #include <stdlib.h>
 #include "../../db/db_res.h"
+#include "../../db/db_con.h"
 #include "../../dprint.h"
 #include "../../mem/mem.h"
 #include "defs.h"
