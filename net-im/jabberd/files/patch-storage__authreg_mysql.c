--- storage/authreg_mysql.c.orig	2018-11-02 00:09:16 UTC
+++ storage/authreg_mysql.c
@@ -20,6 +20,8 @@
 
 /* this module talks to a MySQL server via libmysqlclient */
 
+#include <stdio.h>
+
 #define _XOPEN_SOURCE 500
 #include "c2s.h"
 #include <mysql.h>
