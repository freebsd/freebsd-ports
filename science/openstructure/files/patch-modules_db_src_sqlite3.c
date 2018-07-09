--- modules/db/src/sqlite3.c.orig	2018-07-09 00:05:56 UTC
+++ modules/db/src/sqlite3.c
@@ -15341,7 +15341,7 @@ SQLITE_PRIVATE void sqlite3MemSetDefault
 ** SQLITE_WITHOUT_ZONEMALLOC symbol is defined.
 */
 #include <sys/sysctl.h>
-#include <malloc/malloc.h>
+#include <stdlib.h>
 #include <libkern/OSAtomic.h>
 static malloc_zone_t* _sqliteZone_;
 #define SQLITE_MALLOC(x) malloc_zone_malloc(_sqliteZone_, (x))
