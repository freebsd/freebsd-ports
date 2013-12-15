--- ./storage/authreg_sqlite.c.orig	2013-10-30 12:38:17.000000000 +0000
+++ ./storage/authreg_sqlite.c	2013-12-15 10:29:42.322779475 +0000
@@ -29,6 +29,8 @@
  * to the Jabberd project.
  */
 
+#include <stdio.h>
+
 #define _XOPEN_SOURCE 500
 #include "c2s.h"
 #include <sqlite3.h>
