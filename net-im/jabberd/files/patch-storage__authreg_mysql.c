--- ./storage/authreg_mysql.c.orig	2013-11-12 09:53:47.000000000 +0000
+++ ./storage/authreg_mysql.c	2013-12-15 10:29:42.318779446 +0000
@@ -20,6 +20,8 @@
 
 /* this module talks to a MySQL server via libmysqlclient */
 
+#include <stdio.h>
+
 #define _XOPEN_SOURCE 500
 #include "c2s.h"
 #include <mysql.h>
