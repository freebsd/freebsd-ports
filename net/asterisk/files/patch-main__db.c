--- ./main/db.c.orig	2010-09-10 22:31:58.000000000 +0200
+++ ./main/db.c	2010-11-06 14:54:37.000000000 +0100
@@ -36,6 +36,7 @@
 #include <sys/time.h>
 #include <signal.h>
 #include <dirent.h>
+#include <db.h>
 
 #include "asterisk/channel.h"
 #include "asterisk/file.h"
@@ -46,7 +47,6 @@
 #include "asterisk/utils.h"
 #include "asterisk/lock.h"
 #include "asterisk/manager.h"
-#include "db1-ast/include/db.h"
 
 /*** DOCUMENTATION
 	<manager name="DBGet" language="en_US">
