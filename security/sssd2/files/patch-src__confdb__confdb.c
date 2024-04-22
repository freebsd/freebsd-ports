--- src/confdb/confdb.c.orig	2023-05-05 08:11:07 UTC
+++ src/confdb/confdb.c
@@ -21,6 +21,7 @@
 
 #include "config.h"
 
+#include <sys/param.h>
 #include <ctype.h>
 #include "util/util.h"
 #include "confdb/confdb.h"
@@ -887,7 +888,7 @@ static char *confdb_get_domain_hostname(TALLOC_CTX *me
                                         struct ldb_result *res,
                                         const char *provider)
 {
-    char sys[HOST_NAME_MAX + 1] = {'\0'};
+    char sys[MAXHOSTNAMELEN + 1] = {'\0'};
     const char *opt = NULL;
     int ret;
 
