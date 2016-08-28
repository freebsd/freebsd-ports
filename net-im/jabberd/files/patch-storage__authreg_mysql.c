--- storage/authreg_mysql.c.orig	2016-05-22 15:52:07 UTC
+++ storage/authreg_mysql.c
@@ -20,6 +20,8 @@
 
 /* this module talks to a MySQL server via libmysqlclient */
 
+#include <stdio.h>
+
 #define _XOPEN_SOURCE 500
 #include "c2s.h"
 #include <mysql.h>
