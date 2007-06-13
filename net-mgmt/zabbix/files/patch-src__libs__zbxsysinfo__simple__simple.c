--- ./src/libs/zbxsysinfo/simple/simple.c.orig	Wed Jun 13 15:21:51 2007
+++ ./src/libs/zbxsysinfo/simple/simple.c	Wed Jun 13 15:22:02 2007
@@ -37,6 +37,7 @@
 	};
 
 #ifdef HAVE_LDAP
+#include "ldap.h"
 
 static int    check_ldap(char *hostname, short port, int *value_int)
 {
