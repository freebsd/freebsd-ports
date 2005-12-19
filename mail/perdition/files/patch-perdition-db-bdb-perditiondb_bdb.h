--- perdition/db/bdb/perditiondb_bdb.h.orig	Tue Dec  6 15:58:20 2005
+++ perdition/db/bdb/perditiondb_bdb.h	Tue Dec  6 15:58:34 2005
@@ -29,7 +29,7 @@
 #include <unistd.h>
 #include <stdlib.h>
 #include <ctype.h>
-#include <db.h>
+#include <db3/db.h>
 #include "log.h"
 
 #ifndef PERDITIONDB_BDB_SYSCONFDIR
