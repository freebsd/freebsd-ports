--- perdition/db/bdb/perditiondb_bdb.h.orig	Sun Jun 15 18:38:52 2003
+++ perdition/db/bdb/perditiondb_bdb.h	Sun Jun 15 18:39:05 2003
@@ -29,7 +29,7 @@
 #include <unistd.h>
 #include <stdlib.h>
 #include <ctype.h>
-#include <db.h>
+#include <db3/db.h>
 #include "log.h"
 
 #ifndef PERDITIONDB_BDB_SYSCONFDIR
