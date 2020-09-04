--- src/manage_sqlite3.c.orig	2017-05-02 07:37:19 UTC
+++ src/manage_sqlite3.c
@@ -30,6 +30,7 @@
 #include "manage_utils.h"
 #include "manage_acl.h"
 
+#include <sys/wait.h>
 #include <sqlite3.h>
 #include <time.h>
 #include <unistd.h>
