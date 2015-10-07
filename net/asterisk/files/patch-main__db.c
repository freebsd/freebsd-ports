--- main/db.c.orig	2012-12-10 23:13:48 UTC
+++ main/db.c
@@ -40,6 +40,7 @@ ASTERISK_FILE_VERSION(__FILE__, "$Revisi
 #include <sys/time.h>
 #include <signal.h>
 #include <dirent.h>
+#include <db.h>
 
 #include "asterisk/channel.h"
 #include "asterisk/file.h"
@@ -50,7 +51,6 @@ ASTERISK_FILE_VERSION(__FILE__, "$Revisi
 #include "asterisk/utils.h"
 #include "asterisk/lock.h"
 #include "asterisk/manager.h"
-#include "db1-ast/include/db.h"
 
 /*** DOCUMENTATION
 	<manager name="DBGet" language="en_US">
