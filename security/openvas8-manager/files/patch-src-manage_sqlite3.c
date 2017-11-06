--- src/manage_sqlite3.c.orig	2015-12-08 07:09:32 UTC
+++ src/manage_sqlite3.c
@@ -31,6 +31,7 @@
 #include "manage_acl.h"
 #include "tracef.h"
 
+#include <sys/wait.h>
 #include <sqlite3.h>
 #include <time.h>
 
