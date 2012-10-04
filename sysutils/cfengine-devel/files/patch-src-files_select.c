--- src/files_select.c.orig	2012-10-03 17:59:39.000000000 +0000
+++ src/files_select.c	2012-10-03 18:00:44.000000000 +0000
@@ -27,6 +27,7 @@
 
 #include "env_context.h"
 #include "files_names.h"
+#include "promises.h"
 
 static int SelectTypeMatch(struct stat *lstatptr, Rlist *crit);
 static int SelectOwnerMatch(char *path, struct stat *lstatptr, Rlist *crit);
