
$FreeBSD$

--- modules/postgres/db_mod.c.orig	Wed Oct  8 16:07:22 2003
+++ modules/postgres/db_mod.c	Tue Apr 13 22:27:28 2004
@@ -35,6 +35,7 @@
 
 #include <stdio.h>
 #include "../../sr_module.h"
+#include "../../db/db_con.h"
 #include "dbase.h"
 
 MODULE_VERSION
