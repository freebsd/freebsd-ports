
$FreeBSD$

--- db.c.orig	Fri Jul  9 13:08:09 2004
+++ db.c	Sun Oct 10 15:32:33 2004
@@ -33,7 +33,7 @@
 #include <asterisk/cli.h>
 #include <asterisk/utils.h>
 #include <asterisk/lock.h>
-#include "db1-ast/include/db.h"
+#include <db.h>
 #include "asterisk.h"
 #include "astconf.h"
 
