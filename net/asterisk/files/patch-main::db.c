
$FreeBSD$

--- main/db.c.orig	Fri Jan 13 11:05:32 2006
+++ main/db.c	Fri Jan 13 11:06:55 2006
@@ -35,6 +35,7 @@
 #include <errno.h>
 #include <unistd.h>
 #include <dirent.h>
+#include <db.h>
 
 #include "asterisk.h"
 
@@ -51,7 +52,6 @@ ASTERISK_FILE_VERSION(__FILE__, "$Revisi
 #include "asterisk/utils.h"
 #include "asterisk/lock.h"
 #include "asterisk/manager.h"
-#include "db1-ast/include/db.h"
 
 #ifdef __CYGWIN__
 #define dbopen __dbopen
