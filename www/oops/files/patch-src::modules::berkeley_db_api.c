--- src/modules/berkeley_db_api.c.orig	Tue Oct 15 04:22:09 2002
+++ src/modules/berkeley_db_api.c	Tue Oct 15 04:22:14 2002
@@ -37,7 +37,10 @@
 #endif
 
 #if	defined(HAVE_BERKELEYDB)
-#include	<db.h>
+#include	<db4/db.h>
+/* 
+It should be a tuneable, but since configure accept only db4 it is not a big trouble anyway
+*/
 
 #if	defined(MODULES)
 int		mod_run(void);
