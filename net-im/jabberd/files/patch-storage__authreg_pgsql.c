--- storage/authreg_pgsql.c.orig	2016-05-08 14:30:08 UTC
+++ storage/authreg_pgsql.c
@@ -20,6 +20,8 @@
 
 /* this module talks to a PostgreSQL server via libpq */
 
+#include <stdio.h>
+
 #define _XOPEN_SOURCE 500
 #include "c2s.h"
 #include <libpq-fe.h>
