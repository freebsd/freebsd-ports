--- storage/authreg_sqlite.c.orig	2016-05-03 20:05:25 UTC
+++ storage/authreg_sqlite.c
@@ -29,6 +29,8 @@
  * to the Jabberd project.
  */
 
+#include <stdio.h>
+
 #define _XOPEN_SOURCE 500
 #include "c2s.h"
 #include <sqlite3.h>
