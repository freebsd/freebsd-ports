
$FreeBSD$

--- db.c.orig	Wed Aug 13 18:25:16 2003
+++ db.c	Fri Oct 17 11:27:30 2003
@@ -32,7 +32,7 @@
 #include <asterisk/options.h>
 #include <asterisk/astdb.h>
 #include <asterisk/cli.h>
-#include "db1-ast/include/db.h"
+#include <db.h>
 #include "asterisk.h"
 #include "astconf.h"
 
