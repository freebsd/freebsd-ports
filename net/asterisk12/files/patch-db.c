
$FreeBSD$

--- db.c.orig	Tue Dec  2 17:12:56 2003
+++ db.c	Fri Jan 30 01:47:34 2004
@@ -32,7 +32,7 @@
 #include <asterisk/options.h>
 #include <asterisk/astdb.h>
 #include <asterisk/cli.h>
-#include "db1-ast/include/db.h"
+#include <db.h>
 #include "asterisk.h"
 #include "astconf.h"
 
