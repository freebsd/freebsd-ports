--- ./storage/authreg_pgsql.c.orig	2013-11-12 10:09:39.000000000 +0000
+++ ./storage/authreg_pgsql.c	2013-12-15 10:29:42.320778996 +0000
@@ -20,6 +20,8 @@
 
 /* this module talks to a PostgreSQL server via libpq */
 
+#include <stdio.h>
+
 #define _XOPEN_SOURCE 500
 #include "c2s.h"
 #include <libpq-fe.h>
